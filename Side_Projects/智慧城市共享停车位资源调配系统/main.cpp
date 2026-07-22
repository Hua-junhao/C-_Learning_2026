/**
 * @file main.cpp
 * @brief 智慧城市共享停车位资源动态调配系统
 * @description 本程序包含对问题1、问题2、问题3的核心求解算法。
 *              采用最小费用最大流算法(MCMF)求解全局静态最优分配；
 *              采用时空双因子启发式贪心算法求解离线/在线动态调度。
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const double INF = 1e9; // 定义无穷大，用于网络流初始距离或无法到达的惩罚

// ==================== 1. 数据结构与全局预处理 ====================

// 车位节点定义
struct Spot { int id; double x, y; };

// 车位可用时间窗定义 (对应模型中的[start, end) 左闭右开区间)
struct Slot { int spot_id; double start, end; };

// 用户需求定义
struct User {
    int id; 
    double dest_x, dest_y; // 目的地坐标
    double max_dist;       // 空间约束：最大可忍受步行距离
    double arr, dep;       // 时间窗约束：到达与离开时间
    int index;             // 矩阵索引缓存
};

// 全局缓存矩阵：空间换时间策略，避免在寻优过程中重复进行昂贵的 sqrt 运算
double dist_matrix[505][305]; 

// 车位时间窗哈希表：将 O(N) 的线性查询降维至 O(1) 的哈希查找
map<int, vector<pair<double, double>>> spot_slots_map;

// ==================== 2. 基础计算与工具函数 ====================

/**
 * @brief 计算两点间的欧氏距离
 * 对应模型中的距离计算公式: d = sqrt((x1-x2)^2 + (y1-y2)^2)
 */
double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// 辅助函数：跳过 CSV 文件的表头
void skip_header(ifstream& file) { string line; getline(file, line); }


// ==================== 3. 算法核心逻辑 ====================

/**
 * @brief 资源分配可行性检验函数 (核心约束判定)
 * @param u 当前请求用户
 * @param s_idx 车位数组索引
 * @param s_id 车位实际物理ID
 * @param occ 当前该车位已被占用的时间片段集合
 * @return bool 是否满足所有时空约束
 */
bool can_allocate(const User& u, int s_idx, int s_id, const vector<pair<double, double>>& occ) {
    // 约束 1: 空间距离约束 (超出最大容忍距离则判定无效)
    if (dist_matrix[u.index][s_idx] > u.max_dist) return false;
    
    // 约束 2: 资源开放时段约束 (必须完全包裹用户的停车需求 [arr, dep])
    bool in_slot = false;
    if (spot_slots_map.count(s_id)) {
        for (const auto& sl : spot_slots_map[s_id]) {
            if (u.arr >= sl.first && u.dep <= sl.second) {
                in_slot = true; break;
            }
        }
    }
    if (!in_slot) return false;

    // 约束 3: 资源独占性冲突检验 (遍历已有占用记录，检测时间区间重叠)
    // 重叠判定逻辑: StartA < EndB 且 StartB < EndA
    for (const auto& o : occ) {
        if (u.arr < o.second && o.first < u.dep) return false;
    }
    
    return true; // 满足所有物理与逻辑约束，允许分配
}

// ----------------- 问题 1：最小费用最大流 (MCMF) 模型 -----------------
// 算法复杂度: 能够确保在二分图匹配中找到全局绝对最优解
struct Edge { int to, cap; double cost; int rev; };
vector<vector<Edge>> adj;
vector<double> d_spfa;
vector<int> p_v, p_e;

// 构建残量网络有向边
void add_edge(int from, int to, int cap, double cost) {
    adj[from].push_back({to, cap, cost, (int)adj[to].size()});
    adj[to].push_back({from, 0, -cost, (int)adj[from].size() - 1});
}

// 采用 SPFA 算法寻找带权最短增广路
bool spfa(int S, int T) {
    d_spfa.assign(adj.size(), INF);
    p_v.assign(adj.size(), -1); p_e.assign(adj.size(), -1);
    vector<bool> inq(adj.size(), false);
    queue<int> q;
    d_spfa[S] = 0; q.push(S); inq[S] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            Edge& e = adj[u][i];
            // 精度容差 1e-7，防止浮点数精度引发的死循环
            if (e.cap > 0 && d_spfa[e.to] > d_spfa[u] + e.cost + 1e-7) {
                d_spfa[e.to] = d_spfa[u] + e.cost;
                p_v[e.to] = u; p_e[e.to] = i;
                if (!inq[e.to]) { q.push(e.to); inq[e.to] = true; }
            }
        }
    }
    return d_spfa[T] != INF;
}

void solve_q1(const vector<User>& users, const vector<Spot>& spots) {
    int N = users.size(), M = spots.size();
    int S = 0, T = N + M + 1; // 建立超级源点 S 和超级汇点 T
    adj.assign(T + 1, vector<Edge>());
    
    // 构图：S -> Users -> Spots -> T
    for (int i = 0; i < N; i++) {
        add_edge(S, i + 1, 1, 0); // 容量1限制每个用户最多分配一个车位
        for (int j = 0; j < M; j++) {
            if (dist_matrix[i][j] <= users[i].max_dist)
                add_edge(i + 1, N + 1 + j, 1, dist_matrix[i][j]); // 费用为空间距离
        }
    }
    for (int j = 0; j < M; j++) add_edge(N + 1 + j, T, 1, 0);
    
    int matched = 0; double total_cost = 0;
    // 持续增广直至无法找到可行路径
    while (spfa(S, T)) {
        matched++; total_cost += d_spfa[T];
        for (int v = T; v != S; v = p_v[v]) {
            Edge& e = adj[p_v[v]][p_e[v]];
            e.cap--; adj[v][e.rev].cap++;
        }
    }

    // 解析残量网络并导出最优方案
    ofstream out("q1_allocations.csv");
    out << "user_id,spot_id,dist\n";
    for (int i = 0; i < N; i++) {
        for (auto& e : adj[i + 1]) {
            if (e.to > N && e.to <= N + M && e.cap == 0) {
                int s_idx = e.to - N - 1;
                out << users[i].id << "," << spots[s_idx].id << "," << dist_matrix[i][s_idx] << "\n";
                break;
            }
        }
    }
    out.close();

    cout << "=== 问题1 结果 (MCMF全局最优解) ===" << endl;
    cout << "分配用户数: " << matched << " / " << N << endl;
    if (matched > 0) cout << "平均步行距离: " << total_cost / matched << " 米" << endl;
}

// ----------------- 问题 2：离线时空启发式算法 -----------------
void solve_q2(vector<User> users, const vector<Spot>& spots) {
    // 优化策略：时空双因子排序法
    // 优先满足先到达的用户；若同时到达，优先满足停车时长短的用户以提高资源周转率
    sort(users.begin(), users.end(),[](const User& a, const User& b) {
        if (abs(a.arr - b.arr) > 1e-5) return a.arr < b.arr;
        return (a.dep - a.arr) < (b.dep - b.arr);
    });
    
    map<int, vector<pair<double, double>>> occ; // 占用状态注册表
    int matched = 0; double total_dist = 0;
    
    ofstream out("q2_allocations.csv");
    out << "user_id,spot_id,dist,arr,dep\n";

    for (const auto& u : users) {
        int best_s_idx = -1; double min_d = INF;
        // 贪心搜索：在满足所有硬约束的前提下，寻找距离成本最小的车位
        for (int j = 0; j < (int)spots.size(); j++) {
            double d = dist_matrix[u.index][j];
            if (d < min_d && can_allocate(u, j, spots[j].id, occ[spots[j].id])) {
                min_d = d; best_s_idx = j;
            }
        }
        if (best_s_idx != -1) {
            matched++; total_dist += min_d;
            occ[spots[best_s_idx].id].push_back({u.arr, u.dep}); // 登记锁定
            out << u.id << "," << spots[best_s_idx].id << "," << min_d << "," << u.arr << "," << u.dep << "\n";
        }
    }
    out.close();

    cout << "\n=== 问题2 结果 (离线启发式调度) ===" << endl;
    cout << "分配用户数: " << matched << " / " << users.size() << endl;
    if (matched > 0) cout << "平均步行距离: " << total_dist / matched << " 米" << endl;
}

// ----------------- 问题 3：在线实时分配算法 -----------------
void solve_q3(vector<User> users, const vector<Spot>& spots) {
    // 模拟在线时间轴：严格依照请求发出的物理时间线（先到先服务 FCFS）
    sort(users.begin(), users.end(),[](const User& a, const User& b) {
        if (abs(a.arr - b.arr) > 1e-5) return a.arr < b.arr;
        return a.id < b.id; // 同一时刻按 ID 顺序处理
    });
    
    map<int, vector<pair<double, double>>> occ;
    int matched = 0; double total_dist = 0;
    
    ofstream out("q3_allocations.csv");
    out << "user_id,spot_id,dist,arr,dep\n";

    // 实时决策机制：一旦分配不可反悔
    for (const auto& u : users) {
        int best_s_idx = -1; double min_d = INF;
        for (int j = 0; j < (int)spots.size(); j++) {
            double d = dist_matrix[u.index][j];
            if (d < min_d && can_allocate(u, j, spots[j].id, occ[spots[j].id])) {
                min_d = d; best_s_idx = j;
            }
        }
        if (best_s_idx != -1) {
            matched++; total_dist += min_d;
            occ[spots[best_s_idx].id].push_back({u.arr, u.dep});
            out << u.id << "," << spots[best_s_idx].id << "," << min_d << "," << u.arr << "," << u.dep << "\n";
        }
    }
    out.close();

    cout << "\n=== 问题3 结果 (在线实时算法) ===" << endl;
    cout << "服务用户数: " << matched << " / " << users.size() << endl;
    if (matched > 0) cout << "平均步行距离: " << total_dist / matched << " 米" << endl;
}

// ==================== 主函数启动点 ====================
int main() {
    // 1. 从外部存储加载系统仿真数据
    ifstream fs("spots.csv"), fl("slots.csv"), fu("users.csv");
    if(!fs || !fl || !fu) { 
        cout << "IO Exception: 请确保 spots.csv, slots.csv, users.csv 在当前执行目录下！" << endl; 
        return 0; 
    }
    
    // 解析车位数据
    vector<Spot> spots; skip_header(fs); string line;
    while(getline(fs, line)){
        if(line.empty()) continue;
        stringstream ss(line); string v; Spot s;
        getline(ss,v,','); s.id=stoi(v); 
        getline(ss,v,','); s.x=stod(v); 
        getline(ss,v,','); s.y=stod(v);
        spots.push_back(s);
    }
    
    // 解析时段数据并建立倒排索引
    skip_header(fl);
    while(getline(fl, line)){
        if(line.empty()) continue;
        stringstream ss(line); string v; int id; double st, ed;
        getline(ss,v,','); id=stoi(v); 
        getline(ss,v,','); st=stod(v); 
        getline(ss,v,','); ed=stod(v);
        spot_slots_map[id].push_back({st, ed});
    }

    // 解析请求特征
    vector<User> users; skip_header(fu); int u_count = 0;
    while(getline(fu, line)){
        if(line.empty()) continue;
        stringstream ss(line); string v; User u; u.index = u_count++;
        getline(ss,v,','); u.id=stoi(v); 
        getline(ss,v,','); u.dest_x=stod(v); 
        getline(ss,v,','); u.dest_y=stod(v);
        getline(ss,v,','); u.max_dist=stod(v); 
        getline(ss,v,','); u.arr=stod(v); 
        getline(ss,v,','); u.dep=stod(v);
        users.push_back(u);
    }

    // 2. 初始化核心计算矩阵（静态化空间特征）
    for(int i=0; i<(int)users.size(); i++)
        for(int j=0; j<(int)spots.size(); j++)
            dist_matrix[i][j] = calc_dist(users[i].dest_x, users[i].dest_y, spots[j].x, spots[j].y);

    // 3. 执行系统级优化与调度评估
    solve_q1(users, spots);
    solve_q2(users, spots);
    solve_q3(users, spots);

    return 0;
}
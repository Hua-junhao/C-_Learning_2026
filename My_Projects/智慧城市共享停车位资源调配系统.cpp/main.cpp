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

const double INF = 1e9; // 无穷大

// ==================== 1. 数据结构定义 ====================
struct Spot { int id; double x, y; };
struct Slot { int spot_id; double start, end; };
struct User {
    int id; 
    double dest_x, dest_y, max_dist, arr, dep; 
    int index; // 原始索引
};

// ==================== 2. CSV 解析工具 ====================
// 简单丢弃 CSV 的第一行表头
void skip_bom_and_header(ifstream& file) {
    string line;
    getline(file, line);
}

vector<Spot> read_spots(const string& filename) {
    vector<Spot> spots;
    ifstream file(filename);
    if (!file.is_open()) return spots;
    skip_bom_and_header(file);
    string line;
    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string item;
        Spot s;
        getline(ss, item, ','); s.id = stoi(item);
        getline(ss, item, ','); s.x = stod(item);
        getline(ss, item, ','); s.y = stod(item);
        spots.push_back(s);
    }
    return spots;
}

vector<Slot> read_slots(const string& filename) {
    vector<Slot> slots;
    ifstream file(filename);
    if (!file.is_open()) return slots;
    skip_bom_and_header(file);
    string line;
    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string item;
        Slot s;
        getline(ss, item, ','); s.spot_id = stoi(item);
        getline(ss, item, ','); s.start = stod(item);
        getline(ss, item, ','); s.end = stod(item);
        slots.push_back(s);
    }
    return slots;
}

vector<User> read_users(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (!file.is_open()) return users;
    skip_bom_and_header(file);
    string line;
    int idx = 0;
    while (getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string item;
        User u;
        getline(ss, item, ','); u.id = stoi(item);
        getline(ss, item, ','); u.dest_x = stod(item);
        getline(ss, item, ','); u.dest_y = stod(item);
        getline(ss, item, ','); u.max_dist = stod(item);
        getline(ss, item, ','); u.arr = stod(item);
        getline(ss, item, ','); u.dep = stod(item);
        u.index = idx++;
        users.push_back(u);
    }
    return users;
}

// 计算两点欧氏距离
double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// ==================== 3. 算法核心部分 ====================

// --- 问题1：最小费用最大流 (MCMF) 用于全局最优二分图匹配 ---
struct Edge { int to, cap; double cost; int rev; };
vector<vector<Edge>> adj;
vector<double> dist_spfa;
vector<int> prev_v, prev_e;

void add_edge(int from, int to, int cap, double cost) {
    adj[from].push_back({to, cap, cost, (int)adj[to].size()});
    adj[to].push_back({from, 0, -cost, (int)adj[from].size() - 1});
}

// SPFA 找增广路
bool spfa(int S, int T) {
    dist_spfa.assign(adj.size(), INF);
    prev_v.assign(adj.size(), -1);
    prev_e.assign(adj.size(), -1);
    vector<bool> inq(adj.size(), false);
    queue<int> q;

    dist_spfa[S] = 0;
    q.push(S);
    inq[S] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++) {
            Edge& e = adj[u][i];
            if (e.cap > 0 && dist_spfa[e.to] > dist_spfa[u] + e.cost + 1e-7) { // 加上eps防精度误差
                dist_spfa[e.to] = dist_spfa[u] + e.cost;
                prev_v[e.to] = u;
                prev_e[e.to] = i;
                if (!inq[e.to]) {
                    q.push(e.to);
                    inq[e.to] = true;
                }
            }
        }
    }
    return dist_spfa[T] != INF;
}

void solve_q1(const vector<User>& users, const vector<Spot>& spots) {
    int N = users.size();
    int M = spots.size();
    int S = 0, T = N + M + 1;
    adj.assign(T + 1, vector<Edge>());

    // 建图
    for (int i = 0; i < N; i++) {
        add_edge(S, i + 1, 1, 0); // 源点到用户
        for (int j = 0; j < M; j++) {
            double d = calc_dist(users[i].dest_x, users[i].dest_y, spots[j].x, spots[j].y);
            if (d <= users[i].max_dist) {
                // 用户到车位，容量1，费用为距离
                add_edge(i + 1, N + 1 + j, 1, d);
            }
        }
    }
    for (int j = 0; j < M; j++) {
        add_edge(N + 1 + j, T, 1, 0); // 车位到汇点
    }

    int matched = 0;
    double total_cost = 0;

    // 增广
    while (spfa(S, T)) {
        int min_flow = 1; // 二分图匹配流量恒为1
        matched++;
        total_cost += dist_spfa[T];
        
        for (int v = T; v != S; v = prev_v[v]) {
            Edge& e = adj[prev_v[v]][prev_e[v]];
            e.cap -= min_flow;
            adj[v][e.rev].cap += min_flow;
        }
    }

    cout << "=== 问题1 结果 (不考虑时间) ===" << endl;
    cout << "分配用户数: " << matched << " / " << N << endl;
    if (matched > 0) cout << "平均步行距离: " << total_cost / matched << " 米" << endl;
    cout << "车位利用率: " << (double)matched / M * 100 << "%" << endl;
}

// --- 问题 2 & 3 公用的时间冲突检测与分配逻辑 ---
// occ_intervals 记录每个车位已被占用的时间段
bool can_allocate(const User& u, int spot_id, double d, const vector<Slot>& slots, const vector<pair<double, double>>& occ) {
    if (d > u.max_dist) return false;
    
    // 检查车位本身是否开放该时段
    bool in_slot = false;
    for (const auto& sl : slots) {
        if (sl.spot_id == spot_id && u.arr >= sl.start && u.dep <= sl.end) {
            in_slot = true;
            break;
        }
    }
    if (!in_slot) return false;

    // 检查是否与其他用户时间冲突 (开区间检查)
    for (const auto& o : occ) {
        if (u.arr < o.second && o.first < u.dep) {
            return false; // 有重叠
        }
    }
    return true;
}

// 启发式离线算法 (问题2)
void solve_q2(vector<User> users, const vector<Spot>& spots, const vector<Slot>& slots) {
    // 策略：按照用户的停留时间(短的优先)和到达时间排序，然后贪心分配距离最近的可用车位。
    // 这是一种十分高效的启发式离线策略，在数模中很常用。
    sort(users.begin(), users.end(),[](const User& a, const User& b) {
        double durationA = a.dep - a.arr;
        double durationB = b.dep - b.arr;
        if (abs(durationA - durationB) > 1e-5) return durationA < durationB;
        return a.arr < b.arr;
    });

    map<int, vector<pair<double, double>>> occ_intervals;
    int matched = 0;
    double total_dist = 0;

    for (const auto& u : users) {
        int best_spot = -1;
        double min_d = INF;

        for (const auto& s : spots) {
            double d = calc_dist(u.dest_x, u.dest_y, s.x, s.y);
            if (d < min_d && can_allocate(u, s.id, d, slots, occ_intervals[s.id])) {
                min_d = d;
                best_spot = s.id;
            }
        }

        if (best_spot != -1) {
            matched++;
            total_dist += min_d;
            occ_intervals[best_spot].push_back({u.arr, u.dep});
        }
    }

    cout << "\n=== 问题2 结果 (离线启发式) ===" << endl;
    cout << "分配用户数: " << matched << " / " << users.size() << endl;
    if (matched > 0) cout << "平均步行距离: " << total_dist / matched << " 米" << endl;
}

// 在线算法 (问题3)
void solve_q3(vector<User> users, const vector<Spot>& spots, const vector<Slot>& slots) {
    // 题目要求：严格按照到达时间顺序处理
    sort(users.begin(), users.end(),[](const User& a, const User& b) {
        if (abs(a.arr - b.arr) > 1e-5) return a.arr < b.arr;
        return a.id < b.id; // 同一时刻按 ID
    });

    map<int, vector<pair<double, double>>> occ_intervals;
    int matched = 0;
    double total_dist = 0;

    // TODO: 可以在这里添加 ofstream 记录每一次分配，用于问题4画图
    ofstream out("q3_allocations.csv");
    // out << "user_id,spot_id,dist,arr,dep\n";

    for (const auto& u : users) {
        int best_spot = -1;
        double min_d = INF;

        // 遍历所有车位寻找最近可用
        for (const auto& s : spots) {
            double d = calc_dist(u.dest_x, u.dest_y, s.x, s.y);
            if (d < min_d && can_allocate(u, s.id, d, slots, occ_intervals[s.id])) {
                min_d = d;
                best_spot = s.id;
            }
        }

        if (best_spot != -1) {
            matched++;
            total_dist += min_d;
            occ_intervals[best_spot].push_back({u.arr, u.dep});
            // out << u.id << "," << best_spot << "," << min_d << "," << u.arr << "," << u.dep << "\n";
        }
    }
    // out.close();

    cout << "\n=== 问题3 结果 (在线实时算法) ===" << endl;
    cout << "服务用户数: " << matched << " / " << users.size() << endl;
    if (matched > 0) cout << "平均步行距离: " << total_dist / matched << " 米" << endl;
}

int main() {
    // 1. 读取数据 (如果因为路径问题读不到，请用绝对路径)
    vector<Spot> spots = read_spots("spots.csv");
    vector<Slot> slots = read_slots("slots.csv");
    vector<User> users = read_users("users.csv");

    if(spots.empty() || users.empty()) {
        cout << "数据读取失败，请检查 csv 文件是否在同一目录下！" << endl;
        return 0;
    }

    // 2. 分步求解
    solve_q1(users, spots); // 网络流解决图分配
    solve_q2(users, spots, slots); // 离线启发式调度
    solve_q3(users, spots, slots); // 在线调度

    return 0;
}
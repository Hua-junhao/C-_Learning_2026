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

const double INF = 1e9;

// ==================== 1. 数据结构与全局预处理 ====================
struct Spot { int id; double x, y; };
struct Slot { int spot_id; double start, end; };
struct User {
    int id; 
    double dest_x, dest_y, max_dist, arr, dep; 
    int index; 
};

// 全局缓存，提升效率
double dist_matrix[505][305]; 
map<int, vector<pair<double, double>>> spot_slots_map;

// ==================== 2. 工具函数 ====================
double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void skip_header(ifstream& file) { string line; getline(file, line); }

// ==================== 3. 算法核心逻辑 ====================

// 检查是否可以分配（高效版）
bool can_allocate(const User& u, int s_idx, int s_id, const vector<pair<double, double>>& occ) {
    // 1. 距离检查
    if (dist_matrix[u.index][s_idx] > u.max_dist) return false;
    
    // 2. 车位时段检查 (O(1) 查找)
    bool in_slot = false;
    if (spot_slots_map.count(s_id)) {
        for (const auto& sl : spot_slots_map[s_id]) {
            if (u.arr >= sl.first && u.dep <= sl.second) {
                in_slot = true; break;
            }
        }
    }
    if (!in_slot) return false;

    // 3. 时间冲突检查
    for (const auto& o : occ) {
        if (u.arr < o.second && o.first < u.dep) return false;
    }
    return true;
}

// 问题1：MCMF (保持不变，已是全局最优)
struct Edge { int to, cap; double cost; int rev; };
vector<vector<Edge>> adj;
vector<double> d_spfa;
vector<int> p_v, p_e;

void add_edge(int from, int to, int cap, double cost) {
    adj[from].push_back({to, cap, cost, (int)adj[to].size()});
    adj[to].push_back({from, 0, -cost, (int)adj[from].size() - 1});
}

bool spfa(int S, int T) {
    d_spfa.assign(adj.size(), INF);
    p_v.assign(adj.size(), -1); p_e.assign(adj.size(), -1);
    vector<bool> inq(adj.size(), false);
    queue<int> q;
    d_spfa[S] = 0; q.push(S); inq[S] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++) {
            Edge& e = adj[u][i];
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
    int S = 0, T = N + M + 1;
    adj.assign(T + 1, vector<Edge>());
    for (int i = 0; i < N; i++) {
        add_edge(S, i + 1, 1, 0);
        for (int j = 0; j < M; j++) {
            if (dist_matrix[i][j] <= users[i].max_dist)
                add_edge(i + 1, N + 1 + j, 1, dist_matrix[i][j]);
        }
    }
    for (int j = 0; j < M; j++) add_edge(N + 1 + j, T, 1, 0);
    int matched = 0; double total_cost = 0;
    while (spfa(S, T)) {
        matched++; total_cost += d_spfa[T];
        for (int v = T; v != S; v = p_v[v]) {
            Edge& e = adj[p_v[v]][p_e[v]];
            e.cap--; adj[v][e.rev].cap++;
        }
    }
    cout << "=== 问题1 结果 (全局最优) ===\n分配用户数: " << matched << "\n平均距离: " << (matched?total_cost/matched:0) << endl;
}

// 问题2：离线策略优化
void solve_q2(vector<User> users, const vector<Spot>& spots) {
    // 优化后的排序策略：先按到达时间，再按持续时长
    sort(users.begin(), users.end(), [](const User& a, const User& b) {
        if (abs(a.arr - b.arr) > 1e-5) return a.arr < b.arr;
        return (a.dep - a.arr) < (b.dep - b.arr);
    });
    map<int, vector<pair<double, double>>> occ;
    int matched = 0; double total_dist = 0;
    for (const auto& u : users) {
        int best_s_idx = -1; double min_d = INF;
        for (int j = 0; j < spots.size(); j++) {
            double d = dist_matrix[u.index][j];
            if (d < min_d && can_allocate(u, j, spots[j].id, occ[spots[j].id])) {
                min_d = d; best_s_idx = j;
            }
        }
        if (best_s_idx != -1) {
            matched++; total_dist += min_d;
            occ[spots[best_s_idx].id].push_back({u.arr, u.dep});
        }
    }
    cout << "\n=== 问题2 结果 (离线启发式优化) ===\n分配用户数: " << matched << "\n平均距离: " << (matched?total_dist/matched:0) << endl;
}

// 问题3：在线算法
void solve_q3(vector<User> users, const vector<Spot>& spots) {
    sort(users.begin(), users.end(), [](const User& a, const User& b) {
        if (abs(a.arr - b.arr) > 1e-5) return a.arr < b.arr;
        return a.id < b.id;
    });
    map<int, vector<pair<double, double>>> occ;
    ofstream out("q3_allocations.csv");
    out << "user_id,spot_id,dist,arr,dep\n";
    int matched = 0; double total_dist = 0;
    for (const auto& u : users) {
        int best_s_idx = -1; double min_d = INF;
        for (int j = 0; j < spots.size(); j++) {
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
    cout << "\n=== 问题3 结果 (在线实时算法) ===\n服务用户数: " << matched << "\n平均距离: " << (matched?total_dist/matched:0) << endl;
}

int main() {
    // 数据读取
    ifstream fs("spots.csv"), fl("slots.csv"), fu("users.csv");
    if(!fs || !fl || !fu) { cout << "文件读取失败！"; return 0; }
    
    vector<Spot> spots; skip_header(fs); string line;
    while(getline(fs, line)){
        stringstream ss(line); string v; Spot s;
        getline(ss,v,','); s.id=stoi(v); getline(ss,v,','); s.x=stod(v); getline(ss,v,','); s.y=stod(v);
        spots.push_back(s);
    }
    
    skip_header(fl);
    while(getline(fl, line)){
        stringstream ss(line); string v; int id; double st, ed;
        getline(ss,v,','); id=stoi(v); getline(ss,v,','); st=stod(v); getline(ss,v,','); ed=stod(v);
        spot_slots_map[id].push_back({st, ed});
    }

    vector<User> users; skip_header(fu); int u_idx = 0;
    while(getline(fu, line)){
        stringstream ss(line); string v; User u; u.index = u_idx++;
        getline(ss,v,','); u.id=stoi(v); getline(ss,v,','); u.dest_x=stod(v); getline(ss,v,','); u.dest_y=stod(v);
        getline(ss,v,','); u.max_dist=stod(v); getline(ss,v,','); u.arr=stod(v); getline(ss,v,','); u.dep=stod(v);
        users.push_back(u);
    }

    // 预计算距离矩阵
    for(int i=0; i<users.size(); i++)
        for(int j=0; j<spots.size(); j++)
            dist_matrix[i][j] = calc_dist(users[i].dest_x, users[i].dest_y, spots[j].x, spots[j].y);

    solve_q1(users, spots);
    solve_q2(users, spots);
    solve_q3(users, spots);

    return 0;
}
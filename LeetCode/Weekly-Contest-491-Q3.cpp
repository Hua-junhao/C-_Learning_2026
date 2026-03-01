class Solution {
private:
    int min_val; 
    vector<unordered_set<int>>visited;
    void dfs(int num, int k, vector<vector<int>>& grid) {
        if (k == grid.size()) {
            min_val = min(min_val, num);
            return;
        }
        if (num >= min_val) return;
        if (visited[k].count(num)) return;
        visited[k].insert(num);
        for (int x : grid[k]) {
            int new_num = num | x;
            dfs(new_num, k + 1, grid);
        }
    }
public:
    int minimumOR(vector<vector<int>>& grid) {
        min_val = INT_MAX;
        visited.assign(grid.size(), unordered_set<int>());
        dfs(0, 0, grid);
        return min_val;
    }
};
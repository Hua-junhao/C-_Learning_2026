class Solution {
private:
    int min_val; 
    void dfs(int num, int k, vector<vector<int>>& grid) {
        if (k == grid.size()) {
            min_val = min(min_val, num);
            return;
        }
        for (int x : grid[k]) {
            int new_num = num | x;
            if (new_num >= min_val) {
                continue;
            }
            dfs(new_num, k + 1, grid);
        }
    }
public:
    int minimumOR(vector<vector<int>>& grid) {
        min_val = INT_MAX;
        dfs(0, 0, grid);
        return min_val;
    }
};
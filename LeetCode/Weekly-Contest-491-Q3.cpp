class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        unordered_set<int>dp;
        dp.insert(0);
        for(const auto&row:grid)
        {
            unordered_set<int>next_dp;
            for(int pre_val:dp)
            {
                for(int x:row)
                {
                    next_dp.insert(pre_val|x);
                }
            }
            dp=next_dp;
        }
        int min_val = INT_MAX;
        for(int val:dp)
        {
            min_val=min(min_val,val);
        }
        return min_val;
    }
};
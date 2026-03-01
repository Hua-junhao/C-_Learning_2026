class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        unordered_set<int>dp;
        dp.insert(0);
        for(const auto&row:grid)
        {
            unordered_set<int>next_dp;
            next_dp.reserve(dp.size() * row.size()); 
            for(int pre_val:dp)
            {
                for(int x:row)
                {
                    next_dp.insert(pre_val|x);
                }
            }
            sort(next_dp.begin(), next_dp.end());
            auto last = unique(next_dp.begin(), next_dp.end());
            next_dp.erase(last, next_dp.end());
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
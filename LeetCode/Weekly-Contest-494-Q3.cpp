class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        array<int, 16384> dp;
        dp.fill(-1);
        dp[0] = 0;
        for(int i:nums)
        {
            array<int,16384>next_dp=dp;
            for(int j=0;j<dp.size();j++)
            {
                if(dp[j]!=-1)
                {
                    next_dp[j^i]=max(dp[j^i],dp[j]+1);
                }
            }
            dp=next_dp;
        }
        return dp[target] == -1 ? -1 : nums.size() - dp[target];        
    }
};©leetcode
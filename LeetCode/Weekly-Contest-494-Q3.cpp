class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        vector<int>dp(16384,-1);
        dp[0]=0;
        for(int i:nums)
        {
            vector<int>next_dp=dp;
            for(int j=0;j<dp.size();j++)
            {
                if(dp[j]!=-1)
                {
                    next_dp[j^i]=max(dp[j^i],dp[j]+1);
                }
            }
            dp=next_dp;
        }
        if(dp[target]==-1) return -1;
        return nums.size()-dp[target];
        
    }
};©leetcode
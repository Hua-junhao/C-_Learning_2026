/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxlen=1;
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
// @lc code=end


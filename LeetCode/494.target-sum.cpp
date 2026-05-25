/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        if(abs(target)>sum||(target+sum)%2!=0) return 0;
        int bagsize=(target+sum)/2;
        int n=nums.size();
        vector<int>dp(bagsize+1,0);
        dp[0]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=bagsize;j>=nums[i];--j)
            {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[bagsize];
        
    }
};
// @lc code=end


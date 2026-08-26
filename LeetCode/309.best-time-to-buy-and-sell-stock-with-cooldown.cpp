/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        dp[0][0]=-prices[0];//0:buy(not cooldown) 1:sell 2:cooldown or keep
        for(int i=1;i<n;++i)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
            dp[i][2]=dp[i-1][1];
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};
// @lc code=end


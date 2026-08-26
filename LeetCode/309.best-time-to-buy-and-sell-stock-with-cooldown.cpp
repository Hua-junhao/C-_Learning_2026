/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp(3,0);
        dp[0]=-prices[0];//0:buy(not cooldown) 1:sell 2:cooldown or keep
        for(int price:prices)
        {
            int k=dp[2];
            dp[2]=dp[1];
            dp[0]=max(dp[0],k-price);
            dp[1]=max(dp[1],dp[0]+price);
        }
        return dp[1];
    }
};
// @lc code=end


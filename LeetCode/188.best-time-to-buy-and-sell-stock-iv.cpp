/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>dp(2*k,0);
        for(int i=0;i<2*k;i+=2)
        {
            dp[i]=-prices[0];
        }
        for(int price:prices)
        {
            dp[0]=max(dp[0],-price);
            dp[1]=max(dp[1],dp[0]+price);
            for(int j=2;j<2*k;j+=2)
            {
                dp[j]=max(dp[j],dp[j-1]-price);
                dp[j+1]=max(dp[j+1],dp[j]+price);
            }
        }
        return dp[2*k-1];        
    }
};
// @lc code=end


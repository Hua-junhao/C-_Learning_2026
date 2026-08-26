/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,0));
        for(int i=0;i<2*k;i+=2)
        {
            dp[0][i]=-prices[0];
        }
        for(int i=1;i<n;++i)
        {
            dp[i][0]=max(dp[i-1][0],-prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
            for(int j=2;j<2*k;j+=2)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]+prices[i]);
            }
        }
        return dp[n-1][2*k-1];        
    }
};
// @lc code=end


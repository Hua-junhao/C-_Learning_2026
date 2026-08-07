/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        sort(coins.begin(),coins.end());
        int n=coins.size();
        for(int i=1;i<=amount;++i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(coins[j]<=i)
                {
                    if(dp[i-coins[j]]==INT_MAX) dp[i]=dp[i];
                    else dp[i]=min(dp[i],dp[i-coins[j]]+1);
                } 
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int coin:coins)
        {
            for(int j=coin;j<=amount;++j)
            {
                dp[j]=min(dp[j],dp[j-coin]+1);
            }
        }
        return dp[amount]>amount ? -1 : dp[amount];
        
    }
};
// @lc code=end


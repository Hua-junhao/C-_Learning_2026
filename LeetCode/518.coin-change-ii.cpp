/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        int n=coins.size();
        for(int i=0;i<n;++i)
        {
            for(int j=coins[i];j<=amount;++j)
            {
                if(dp[j]<INT_MAX-dp[j-coins[i]]) dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end


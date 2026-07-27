/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int>dp(amount+1,0);
        dp[0]=1;
        for(int coin:coins)
        {
            for(int j=coin;j<=amount;++j)
            {
                dp[j]+=dp[j-coin];
            }
        }
        return static_cast<int>(dp[amount]);
    }
};
// @lc code=end


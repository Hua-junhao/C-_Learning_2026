/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int amount=sqrt(n)+1;
        vector<int>dp(n+1,n);
        dp[0]=0;
        for(int i=1;i<=amount;++i)
        {
            int k=i*i;
            for(int j=k;j<=n;++j)
            {
                dp[j]=min(dp[j],dp[j-k]+1);
            }
        }
        return dp[n];
        
    }
};
// @lc code=end


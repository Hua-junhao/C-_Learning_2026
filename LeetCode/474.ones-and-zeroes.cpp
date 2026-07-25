/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(const string& str:strs)
        {
            int zeronum=count(str.begin(),str.end(),'0');
            int onenum=str.size()-zeronum;
            for(int i=m;i>=zeronum;i--)
            {
                for(int j=n;j>=onenum;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-zeronum][j-onenum]+1);
                }
            }
        }
        return dp[m][n];
        
    }
};
// @lc code=end


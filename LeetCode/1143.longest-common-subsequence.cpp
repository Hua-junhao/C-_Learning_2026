/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()<text2.size()) return longestCommonSubsequence(text2,text1);
        int n=text1.size();
        int m=text2.size();
        vector<int>dp(m+1);
        for(int i=1;i<=n;++i)
        {
            int pre=0;
            for(int j=1;j<=m;++j)
            {
                int temp=dp[j];
                if(text1[i-1]==text2[j-1]) dp[j]=pre+1;
                else dp[j]=max(dp[j-1],dp[j]);
                pre=temp;
            }
        }
        return dp[m];
        
    }
};
// @lc code=end


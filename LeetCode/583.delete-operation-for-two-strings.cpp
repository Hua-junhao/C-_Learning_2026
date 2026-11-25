/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m<n) return minDistance(word2,word1);
        int dp[505]={0};
        for(int i=1;i<=m;++i)
        {
            int pre=0;
            const char c=word1[i-1];
            for(int j=1;j<=n;++j)
            {
                int temp=dp[j];
                if(c==word2[j-1]){
                    dp[j]=pre+1;
                }  
                else{
                    dp[j]=max(dp[j],dp[j-1]);
                } 
                pre=temp;
            }
        }
        return m+n-2*dp[n];
        
    }
};
// @lc code=end


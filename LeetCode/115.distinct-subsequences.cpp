/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        const int m=s.size();
        const int n=t.size();
        if (m < n) return 0;
        vector<uint64_t>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=m;++i){
            const char sc=s[i-1];
            const int upper_bound=min(n,i);
            const int lower_bound=max(1,n-(m-i));
            for(int j=upper_bound;j>=lower_bound;--j){
                if(sc==t[j-1]){
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                string str=s.substr(j,i-j);
                if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end() && dp[j]) dp[i]=true;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end


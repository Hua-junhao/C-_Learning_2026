/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        int max_len=0;
        for(const string& word:wordDict)
        {
            max_len=max(max_len,static_cast<int>(word.size()));
        }
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;++i)
        {
            for(int j=i-1;j>=max(0,i-max_len);--j)
            {
                if(dp[j] && wordset.count(s.substr(j,i-j))) 
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end


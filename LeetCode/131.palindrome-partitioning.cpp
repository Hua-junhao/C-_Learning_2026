/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    void backtracking(const string&s,int startIndex,vector<vector<string>>&result,vector<string>&path, const vector<vector<bool>>& isPal)
    {
        if(startIndex>=s.size()) 
        {
            result.push_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();++i)
        {
            if(!isPal[startIndex][i]) continue;
            path.push_back(s.substr(startIndex,i-startIndex+1));     
            backtracking(s,i+1,result,path,isPal);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;
        int n=s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = i; j < n; j++) 
            {
                if (s[i] == s[j] && (j - i <= 1 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        backtracking(s,0,result,path,isPal);
        return result;
        
    }
};
// @lc code=end


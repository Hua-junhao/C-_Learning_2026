/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(const string&s,int startIndex,int i)
    {
        while(startIndex<i)
        {
            if(s[startIndex]!=s[i]) return false;
            startIndex++;
            i--;
        }
        return true;
    }
    void backtracking(const string&s,int startIndex,vector<vector<string>>&result,vector<string>&path)
    {
        if(startIndex>=s.size()) 
        {
            result.push_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();++i)
        {
            if(!isPalindrome(s,startIndex,i)) continue;
            path.push_back(s.substr(startIndex,i-startIndex+1));     
            backtracking(s,i+1,result,path);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;
        backtracking(s,0,result,path);
        return result;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    void backtracking(string lettermap[],string&digits,int index,string&path,vector<string>&result)
    {
        if(index==digits.size())
        {
            result.push_back(path);
            return;
        }
        string s=lettermap[digits[index]-'2'];
        for(int i=0;i<s.size();++i)
        {
            path.push_back(s[i]);
            backtracking(lettermap,digits,index+1,path,result);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string lettermap[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        if (digits.empty()) return result;
        string path;
        int index=0;
        backtracking(lettermap,digits,index,path,result);
        return result;   
    }
};
// @lc code=end


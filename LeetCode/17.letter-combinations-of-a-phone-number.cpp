/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
    string lettermap[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void backtracking(string&digits,int index,string&path,vector<string>&result)
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
            backtracking(digits,index+1,path,result);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if (digits.empty()) return result;
        string path;
        int index=0;
        backtracking(digits,index,path,result);
        return result;   
    }
};
// @lc code=end


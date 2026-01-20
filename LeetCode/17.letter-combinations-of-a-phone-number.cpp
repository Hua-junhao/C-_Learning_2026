/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string>result;
    void func(vector<string>str,int i,int n,string s)
    {
        if(i==n)
        {
            result.push_back(s);
            s="";
            return;
        }
        for(char c:str[i])
        {
            func(str,i+1,n,s+c);
        }

    }
    vector<string> letterCombinations(string digits) {
        string arr[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        vector<string>str;
        for(int i=0;i<n;i++)
        {
            str.push_back(arr[digits[i]-'2']);
        }
        
        func(str,0,n,"");
        return result;    
    }
};
// @lc code=end


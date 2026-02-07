/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string result="";
        string a="";
        int i=s.size()-1;
        while(i>=0)
        {
            if(s[i]==' ')
            {
                if(a!="")
                {
                   if(result=="") 
                   {
                     result=a;
                   }
                   else
                   {
                     result+=" "+a;
                   }
                }
                a="";  
            }
            else
            {
                a=s[i]+a;
            }
            i--;
        }
        if (a!="")
        {
            if(result=="") 
            {
                result=a;
            }
            else
            {
                result+=" "+a;
            }
        }
        return result;

    }
};
// @lc code=end


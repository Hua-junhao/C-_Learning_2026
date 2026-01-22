/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        string a="";
        for (char c: s)
        {
            if(c=='('||c=='['||c=='{')
            {
                a.push_back(c);
            }
            else
            {
                if(a.empty()) return false;
                if ((c == ')' && a.back() == '(')||(c == ']' && a.back() == '[')||(c == '}' && a.back() == '{')) 
                {
                    a.pop_back();
                }
                else{
                    return false;
                }
            }
        }    
        if(a.empty()) return true;
        return false;
    }
};
// @lc code=end


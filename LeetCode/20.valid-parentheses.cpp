/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        string st="";
        for (char c: s)
        {
            if (c == '(') 
            {
                st.push_back(')');
            } 
            else if (c == '{') 
            {
                st.push_back('}');
            } 
            else if (c == '[') 
            {
                st.push_back(']');
            } 
            else 
            {
                if (st.empty() || st.back() != c)
                {
                    return false;
                }
                st.pop_back();
            }
        }    
        return st.empty();
    }
};
// @lc code=end


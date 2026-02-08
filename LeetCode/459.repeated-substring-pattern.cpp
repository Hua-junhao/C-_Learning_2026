/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled=s+s;
        string modified=doubled.substr(1,doubled.size()-2);
        return modified.find(s)!=string::npos;
    
    }
};
// @lc code=end


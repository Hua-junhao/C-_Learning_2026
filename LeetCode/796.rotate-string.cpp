/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()) return false;
        string double_s=s+s;
        return double_s.find(goal)!=string::npos;
    }
};
// @lc code=end


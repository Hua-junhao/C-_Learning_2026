/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0,n=s.size();
        for(int i=0;i<n;i+=2*k)
        {
            reverse(s.begin()+i,s.begin()+min(i+k,n));
        }
        return s;
    }
};
// @lc code=end


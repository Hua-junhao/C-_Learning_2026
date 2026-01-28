/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        for(int i=0;i<n1-n2+1;i++)
        {
            string a =haystack.substr(i,n2);
            if(a==needle)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end


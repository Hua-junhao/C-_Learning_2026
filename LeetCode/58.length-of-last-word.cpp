/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1,r=n;
        while(n>=0&&(!(s[n]<='z'&&s[n]>='a')&&!(s[n]<='Z'&&s[n]>='A')))
        {
            n--;
        }
        r=n;
        while(n>=0&&((s[n]<='z'&&s[n]>='a')||(s[n]<='Z'&&s[n]>='A')))
        {
            n--;
        }
        return r-n;
        
    }
};
// @lc code=end


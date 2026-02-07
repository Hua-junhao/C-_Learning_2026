/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            if(s[r]!=' ')
            {
                if(l!=0)
                {
                    s[l++]=' ';
                }
            }
            while(r<s.size()&&s[r]!=' ')
            {
                s[l++]=s[r++];
            }
        }
        s.resize(l);
        reverse(s.begin(),s.end());
        l=0;
        for(int r=0;r<=s.size();r++)
        {
            if(r==s.size()||s[r]==' ')
            {
                reverse(s.begin()+l,s.begin()+r);
                l=r+1;
            }
        }
        return s;
    }
};
// @lc code=end


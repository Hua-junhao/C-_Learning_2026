/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>v1;
        vector<char>v2;
        for(char c:s)
        {
            if(c!='#')
            {
                v1.push_back(c);
            }
            else if(v1.size()>0)
            {
                v1.pop_back();
            }
        }
        for(char c:t)
        {
            if(c!='#')
            {
                v2.push_back(c);
            }
            else if(v2.size()>0)
            {
                v2.pop_back();
            }
        }
        int n=v1.size();
        if(n!=v2.size())
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


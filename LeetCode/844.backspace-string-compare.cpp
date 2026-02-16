/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1,j=t.size()-1,skips=0,skipt=0;
        while (i>=0||j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    skips++;
                }
                else if(skips>0)
                {
                    skips--;
                }
                else
                {
                    break;
                }
                i--;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    skipt++;
                }
                else if(skipt>0)
                {
                    skipt--;
                }
                else
                {
                    break;
                }
                j--;
            }
            if(i>=0&&j>=0)
            {
                if(s[i]!=t[j])
                {
                    return false;
                }
            }
            else if(i>=0||j>=0)
            {
                return false;
            }
            i--;
            j--;
        }
        return true;

    }
};
// @lc code=end


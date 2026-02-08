/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(n%(i+1)!=0)
            {
                continue;
            }
            else
            {
                string s1=s.substr(0,i+1);
                int n1=s1.size();
                bool flag=1;
                for(int j=i+1;j<n;j+=n1)
                {
                    string s2=s.substr(j,n1);
                    if(s2!=s1)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    return true;
                }
            }
        }
        return false;    
    
    }
};
// @lc code=end


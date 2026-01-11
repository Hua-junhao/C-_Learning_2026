/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private :
    int expand (const string &s,int left ,int right)
    {   while (true)
        {
            if (left <0||right>=s.size()||s[left]!=s[right])
            {
             return (right-left-1);
            }
            else
            {
                right ++;
                left --;
            }
        }
        
    }
public:
    string longestPalindrome(string s) 
    {
        if (s.size()<2) return s;
        int start =0;
        int maxlen=1;
        for (int i=0;i<s.size();i++)
        {
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if (len>maxlen)
            {
                maxlen=len;
                if (len%2==0) start=i-len/2+1;
                else start =i-len/2;
            }
        }
        string ls=s.substr(start,maxlen);
        return ls;    
    }
};
// @lc code=end


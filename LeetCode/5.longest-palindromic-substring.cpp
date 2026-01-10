/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
     bool isPalindrome(const string  &s,int left,int right)
    {
        while (left<right)
        {
            if (s[left]!=s[right]) return 0;
            left++;
            right--;
        }
        return 1;
    }
    string longestPalindrome(string s) 
    {
        if (s.size()==1) return s;
        string maxs=s.substr(0,1);
        for (int left=0;left<s.size()-1;left++)
        { 
            string news="";
           for (int right=left+1;right<s.size();right++)
           {
            if (isPalindrome(s,left,right))
            {
                news=s.substr(left,right-left+1);
            }
            if (news.size()>maxs.size())
            {
                maxs=news;
            }
           }
        }
        return maxs;
        
    }
};
// @lc code=end


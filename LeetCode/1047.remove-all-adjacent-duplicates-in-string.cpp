/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        int n=s.size();
        if(n==1) return s;
        while(i<n-1)
        {
            if(s[i]==s[i+1]){
                n-=2;
                s.erase(i,2);
                if(i>0)i--;
            }
            else i++;
        }
        return s;
    }
};
// @lc code=end


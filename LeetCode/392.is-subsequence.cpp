/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        const int m=s.size();
        const int n=t.size();
        while(i<m && j<n)
        {
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }
};
// @lc code=end


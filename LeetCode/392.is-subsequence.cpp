/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=1,j=-1,n=t.size(),m=s.size();
        if(m==0) return true;
        if(m>n) return false;
        for(int k=0;k<n;++k)
        {
            if(t[k]==s[0]){
                j=k;
                break;
            }
        }
        if(j==-1) return false;
        j++;
        while(j<n&&i<m)
        {
            if(s[i]==t[j]) i++;
            j++;
        }
        return i==m;
    }
};
// @lc code=end


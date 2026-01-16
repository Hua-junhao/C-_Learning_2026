/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int min=strs[0].size();
        for(int i=1;i<n;i++)
        {
            if(strs[i].size()<min) min=strs[i].size();
        }
        for(int i=0;i<min;i++)
        {
            char a=strs[0][i];
            for(int j=1;j<n;j++)
            {
                if(a!=strs[j][i]) 
                {
                    if(i==0)return"";
                    else return strs[0].substr(0,i);
                }
            }
        }
        return strs[0].substr(0,min);
    }
};
// @lc code=end


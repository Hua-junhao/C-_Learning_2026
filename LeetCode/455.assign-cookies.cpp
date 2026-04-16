/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1,j=s.size()-1,k=0;
        while(i>=0&&j>=0)
        {
            if(s[j]>=g[i])
            {
                k++;
                j--;
            }
            i--;
        }
        return k;
        
    }
};
// @lc code=end


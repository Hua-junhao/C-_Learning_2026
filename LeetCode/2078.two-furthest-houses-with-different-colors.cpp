/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0,r=l+1,n=colors.size(),maxdis=0;
        while(l<n)
        {
            while(r<n)
            {
                if(colors[r]!=colors[l]) maxdis=max(maxdis,r-l);
                r++;
            }
            l++;
            r=l+1;
            if(n-1-l<=maxdis) break;
        }
        return maxdis;
        
    }
};
// @lc code=end


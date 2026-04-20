/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(),maxdis=0;
        for(int i=n-1;i>0;--i)
        {
            if(colors[i]!=colors[0])
            {
                maxdis=i;
                break;
            } 
        }
        for(int i=1;i<n-1;++i)
        {
            if(colors[i]!=colors[n-1])
            {
                maxdis=max(maxdis,n-1-i);
                break;
            }
        }
        return maxdis;
        
    }
};
// @lc code=end


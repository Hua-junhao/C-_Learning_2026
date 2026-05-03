/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(goal.size()!=n) return false;
        for(int i=0;i<n;++i)
        {
            int l=i,r=0;
            while(r<n&&s[r]==goal[l])
            {
                l=(l+1)%n;
                r=r+1;
            }
            if(r==n) return true;
        }
        return false;
    }
};
// @lc code=end


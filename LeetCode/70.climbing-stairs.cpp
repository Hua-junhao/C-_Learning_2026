/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int pre=1;
        int cur=2;
        if(n<=2) return n; 
        for(int i=3;i<=n;++i)
        {
            int sum=pre+cur;
            pre=cur;
            cur=sum;
        }
        return cur;
        
    }
};
// @lc code=end


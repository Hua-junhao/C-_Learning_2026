/*
 * @lc app=leetcode id=3783 lang=cpp
 *
 * [3783] Mirror Distance of an Integer
 */

// @lc code=start
class Solution {
public:
    long long Reverse(int n)
    {
        long long num=0;
        while(n>0)
        {
            num=num*10+n%10;
            n=n/10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n-Reverse(n));
        
    }
};
// @lc code=end


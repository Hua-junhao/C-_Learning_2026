/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int powsum(int n)
    { 
        int sum=0;
        while (n>0)
        {
            int a=n%10;
            sum+=a*a;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=powsum(n);
        while(slow!=fast&&fast!=1)
        {
            slow=powsum(slow);
            fast=powsum(powsum(fast));
        }        
        return fast==1;
        
    }
};
// @lc code=end


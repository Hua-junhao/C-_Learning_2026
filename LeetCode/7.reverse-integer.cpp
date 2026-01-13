/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
    int  num=0;
    while (x!=0) 
    {
       int a=x%10;
       x=x/10;
       if (num>INT_MAX/10||(num==INT_MAX/10&&a>7)) return 0;
       if (num<INT_MIN/10||(num==INT_MIN/10&&a<-8)) return 0;
       num=num*10+a;
    }
    return num; 
    }
};
// @lc code=end


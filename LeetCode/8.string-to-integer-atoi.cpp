/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
    long long num=0;
    bool flag=0;
    int x=1;
    for(char c:s)
    {
        if(c==' ') 
        {
            if(flag) break;
            continue;
        }
        if(c=='-'||c=='+') 
        {
            if(flag) break;
            if(c=='-') x=-1;
            flag=true;
            continue;
        }
        if(c >= '0' && c <= '9') 
        {
            flag=1;
            int a=c-'0';
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && a > 7)) return (x == 1) ? INT_MAX : INT_MIN;
            num=a+num*10;
        }
        else break;
    }
    return num*x;  
    }
};
// @lc code=end


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
        unordered_set<int>set;
        while(n!=1&&set.find(n)==set.end())
        {
            set.insert(n);
            n=powsum(n);
        }
        return n==1;
        
    }
};
// @lc code=end


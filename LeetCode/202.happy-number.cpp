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
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>set;
        set.insert(n);
        while(n!=1)
        {
            n=powsum(n);
            if(set.find(n)!=set.end())
            {
                return false;
            }
            set.insert(n);
        }
        return true;
        
    }
};
// @lc code=end


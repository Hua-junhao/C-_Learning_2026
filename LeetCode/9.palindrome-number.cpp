/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int>v;
        int num=x;
        if(x<0) return false;
        while (num>0)
        {
            v.push_back(num%10);
            num/=10;
        }
        int left=0;
        int right=v.size()-1;
        while (left<=right)
        {
            if(v[left]!=v[right]) return false;
            left++;
            right--;
        }
        return true;       
    }
};
// @lc code=end


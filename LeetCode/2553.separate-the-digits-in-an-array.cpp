/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        result.reserve(nums.size()*3);
        int buff[10];
        for(int num:nums)
        {
            int idx=0;
            while(num>0)
            {
                buff[idx++]=num%10;
                num/=10;
            }
            for(int i=idx-1;i>=0;--i)
            {
                result.push_back(buff[i]);
            }
        }
        return result;
        
    }
};
// @lc code=end


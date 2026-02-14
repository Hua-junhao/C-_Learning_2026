/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd=1,even=0;
        int n=nums.size();
        while(odd<n&&even<n)
        {
            while(even<n&&nums[even]%2==0)
            {
                even+=2;
            }
            while(odd<n&&nums[odd]%2==1)
            {
                odd+=2;
            }
            if(odd<n&&even<n)
            {
                swap(nums[even],nums[odd]);
            }
        }
        return nums;
         
    }
};
// @lc code=end


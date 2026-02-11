/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]!=0)
            {
                nums[l]=nums[r];
                l++;
            }
        }
        for(int i=l;i<nums.size();i++)
        {
            nums[i]=0;
        }
        
    }
};
// @lc code=end


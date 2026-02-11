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
                
                if(l!=r)
                {
                    swap(nums[l],nums[r]);
                }
                l++;
            }
        }
        
    }
};
// @lc code=end


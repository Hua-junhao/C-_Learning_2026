/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[l-1])
            {
                nums[l]=nums[i];
                l++;
            }
        }
        return l;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            if(nums[l]==target)
            {
                return l;
            }
            else if (nums[r]==target)
            {
                return r;
            }
            r--;
            l++;
        }
        return -1;
        
    }
};
// @lc code=end


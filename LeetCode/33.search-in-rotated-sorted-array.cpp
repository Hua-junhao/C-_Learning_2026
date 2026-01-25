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
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]>=nums[l])//nums[mid]==nums[l]时，左半边有序(eg.[3,1])
            {
                if(nums[l]<=target&&nums[mid]>target)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[r]>=target&&nums[mid]<target)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


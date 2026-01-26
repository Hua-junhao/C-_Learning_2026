/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int>result{-1,-1};
        while (l<=r)//找左端点
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                result[0]=mid;
                r=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        l=0,r=nums.size()-1;
        while (l<=r)//找右端点
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                result[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return result;
        
    }
};
// @lc code=end


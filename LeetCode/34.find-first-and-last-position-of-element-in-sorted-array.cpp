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
        while (l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                l=mid;
                r=mid;
                break;
            }
        }
        if(l>r)
        {
            return {-1,-1};
        }
        else
        {
            while(l>0&&nums[l-1]==target)
            {
                l--;
            }
            while(r<nums.size()-1&&nums[r+1]==target)
            {
                r++;
            }
        }
        return {l,r};
        
    }
};
// @lc code=end


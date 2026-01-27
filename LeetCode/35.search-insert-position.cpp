/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result=0,l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid =l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                result=mid+1;
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


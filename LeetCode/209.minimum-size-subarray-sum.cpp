/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=l,sum=0,n=nums.size(),minlen=INT_MAX;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                minlen=min(r-l+1,minlen);
                sum-=nums[l];
                l++;
            }
            r++;  
        }
        return (minlen==INT_MAX) ? 0:minlen;
    }
};
// @lc code=end


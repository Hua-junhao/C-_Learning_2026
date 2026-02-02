/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=l,sum=0,n=nums.size(),s=n+1;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                if(r-l+1<s)
                {
                    s=r-l+1;
                }
                sum-=nums[l];
                l++;
            }
            r++;  
        }
        if(s!=n+1)
        {
            return s;
        }
        else
        {
            return 0;
        }
    }
};
// @lc code=end


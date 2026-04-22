/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxsum=INT_MIN;
        for(int num:nums)
        {
            sum+=num;
            maxsum=max(sum,maxsum);
            if(sum<0) sum=0;
        }
        return maxsum;
    }
};
// @lc code=end


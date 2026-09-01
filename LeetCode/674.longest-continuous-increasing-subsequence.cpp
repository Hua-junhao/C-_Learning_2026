/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int maxlen=1;
        int count=1;
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
            {
                count++;
            }
            else count=1;
            maxlen=max(maxlen,count);
        }
        return maxlen;
    }
};
// @lc code=end


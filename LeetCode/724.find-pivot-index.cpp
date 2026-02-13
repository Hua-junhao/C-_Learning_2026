 /*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int leftsum=0;
        for (int s:nums)
        {
            sum+=s;
        }
        for(int i=0;i<n;i++)
        {
            if(sum-nums[i]==leftsum*2)
            {
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};
// @lc code=end


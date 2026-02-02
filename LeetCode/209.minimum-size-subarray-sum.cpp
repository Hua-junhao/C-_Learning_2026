/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),len=n+1;
        for(int i=0;i<n;i++)
        {
            int sum=nums[i];
            int s=1;
            for(int j=i+1;j<n;j++)
            {
                if(sum<target)
                {
                    sum+=nums[j];
                    s++;
                }
                else
                {
                    break;
                }
            }
            if(sum<target)
            {
                break;
            }
            else
            {
                if(s<len)
                {
                    len=s;
                }
            }
        }
        if(len!=n+1)
        {
            return len;
        }
        else
        {
            return 0;
        }
        
    }
};
// @lc code=end


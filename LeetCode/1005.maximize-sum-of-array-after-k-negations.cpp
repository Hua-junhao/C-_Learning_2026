/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n&&nums[i]<0)
        {
            if(k>0)
            {
                nums[i]=abs(nums[i]);
                k--;
            }
            i++;
        }
        if(k%2==1)
        {
            if(i==n) nums[i-1]=nums[i-1]*(-1);
            else if(i==0) nums[i]=nums[i]*(-1);
            else if(nums[i]>nums[i-1]) nums[i-1]=nums[i-1]*(-1);
            else nums[i]=nums[i]*(-1);
        }
        int sum=0;
        for(int a:nums) sum+=a;
        return sum;
        
    }
};
// @lc code=end


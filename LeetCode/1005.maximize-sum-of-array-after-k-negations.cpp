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
        for(int i=0;i<nums.size();++i)
        {
            if(k>0&&nums[i]<0)
            {
                nums[i]=abs(nums[i]);
                k--;
            }
            
        } 
        sort(nums.begin(),nums.end());   
        if(k%2==1) nums[0]=nums[0]*(-1);
        int sum=0;
        for(int i:nums) sum+=i;
        return sum;
        
    }
};
// @lc code=end


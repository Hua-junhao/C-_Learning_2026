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
        int n=nums.size();
        for (int i = 0; i < n && nums[i] < 0 && k > 0; ++i) {
            nums[i] = abs(nums[i]);
            k--;
        }
        int sum=0,min_mal=INT_MAX;
        for(int a:nums) 
        {
            sum+=a;
            min_mal=min(min_mal,a);
        }
        if(k%2==1) sum-=min_mal*2;
        return sum;
        
    }
};
// @lc code=end


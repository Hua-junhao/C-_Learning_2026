/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>result;
        for(int i=0;i<n-2;i++)
        {    
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum=nums[l]+nums[r]+nums[i];
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};
// @lc code=end


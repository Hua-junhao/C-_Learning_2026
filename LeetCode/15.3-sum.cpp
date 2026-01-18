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
            if(nums[i]>0){
                break;
            }
            int l=i+1;
            int r=n-1;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            while(l<r)
            {
                long long sum=nums[l]+nums[r];
                if(sum==(-1)*nums[i]){
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<r&&nums[r]==nums[r+1]){
                        r--;
                    }
                    if(l>=r){
                        break;
                    }
                }
                if(sum>(-1)*nums[i]){
                    r--;
                    while(l<r&&nums[r]==nums[r+1]){
                        r--;
                    }
                }
                if(sum<(-1)*nums[i]){
                    l++;
                    while(l<r&&nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end


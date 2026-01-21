/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>result;
        for(int i=0;i<n-3;i++)
        {
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if(i>0&&nums[i]==nums[i-1])continue;
            long long t=target-nums[i];
            for(int j=i+1;j<n-2;j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                if ((long long)nums[j] + nums[j+1] + nums[j+2] > t) break;
                int l=j+1;
                int r=n-1;
                while(l<r)
                {
                    long long s=(long long)nums[j]+nums[l]+nums[r];
                    if(s==t)
                    {
                        result.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                    if(s<t)
                    {
                        l++;
                    }
                    if(s>t)
                    {
                        r--;
                    }

                }
            }
        }
        return result;
    }
};
// @lc code=end


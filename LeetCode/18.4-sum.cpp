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
        if(n<4) return result;
        for(int i=0;i<n-3;i++)
        {
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
             if ((long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int l=j+1;
                int r=n-1;
                while(l<r)
                {
                    long long s=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(s>target)
                    {
                        r--;
                    }
                    else if(s<target)
                    {
                        l++;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    }

                }
            }
        }
        return result;
    }
};
// @lc code=end


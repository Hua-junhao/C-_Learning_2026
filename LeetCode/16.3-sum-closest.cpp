/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min=abs(nums[0]+nums[1]+nums[2]-target);
        int minsum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {    
            int l=i+1;
            int r=n-1;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            while(l<r)
            {
                long long sum=nums[l]+nums[r]+nums[i];
                if(min>abs(sum-target))
                {
                    min=abs(sum-target);
                    minsum=sum;
                }
                if(sum==target){
                    return target;
                }
                if(sum>target){
                    r--;
                    while(l<r&&nums[r]==nums[r+1]){
                        r--;
                    }
                }
                if(sum<target){
                    l++;
                    while(l<r&&nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return minsum;
        
    }
};
// @lc code=end


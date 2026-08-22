/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int func(vector<int>& nums,int start,int end) {
        int pre=0;//dp[i-2]
        int cur=0;//dp[i-1]
        for(int i=start;i<end;++i)
        {
            int next=max(cur,pre+nums[i]);
            pre=cur;
            cur=next;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(func(nums,1,n),max(func(nums,0,n-1),func(nums,1,n-1)));
    }
};
// @lc code=end


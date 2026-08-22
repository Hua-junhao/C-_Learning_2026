/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre=0;//dp[i-2]
        int cur=0;//dp[i-1]
        for(int num:nums)
        {
            int next=max(cur,pre+num);
            pre=cur;
            cur=next;
        }
        return cur;
    }
};
// @lc code=end


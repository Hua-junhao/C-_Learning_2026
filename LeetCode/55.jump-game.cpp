/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=nums[0],n=nums.size()-1;
        for(int i=0;i<=k;i++)
        {
            if(i==n) return true;
            k=max(k,i+nums[i]);
        }
        return false;
        
    }
};
// @lc code=end


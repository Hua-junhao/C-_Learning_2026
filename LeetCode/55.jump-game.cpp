/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0,n=nums.size();
        if(n<=1) return true;
        for(int i=0;i<=max_reach;++i)
        {
            max_reach=max(max_reach,i+nums[i]);
            if(max_reach>=n-1) return true;
        }
        return false;

    }
};
// @lc code=end
    

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0,n=nums.size(),curcover=0,nextcover=0;
        if(n<=1) return step;
        for(int i=0;i<n-1;++i)
        {
            nextcover=max(nextcover,nums[i]+i);
            if(nextcover>=n-1) return step+1;
            if(i==curcover)
            {
                step++;
                curcover=nextcover;
            }
        }
        return step;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;++i)
        {
            for(int num:nums)
            {
                if(i>=num){
                    dp[i]+=dp[i-num];
                }
            }
        }
        return static_cast<int>(dp[target]);
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<int>&nums,vector<vector<int>>&result,int first)
    {
        if(first==nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=first;i<nums.size();++i)
        {
           swap(nums[first],nums[i]);
           backtracking(nums,result,first+1);
           swap(nums[first],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        backtracking(nums,result,0);
        return result;
        
    }
};
// @lc code=end


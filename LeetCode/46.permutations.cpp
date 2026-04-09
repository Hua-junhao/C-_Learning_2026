/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<int>&nums,vector<vector<int>>&result,vector<int>&path,int (&used)[21])
    {
        if(path.size()==nums.size())
        {
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(used[nums[i]+10]==1) continue;
            path.push_back(nums[i]);
            used[nums[i]+10]=1;
            backtracking(nums,result,path,used);
            path.pop_back();
            used[nums[i]+10]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int used[21]={0};
        vector<int>path;
        vector<vector<int>>result;
        backtracking(nums,result,path,used);
        return result;
        
    }
};
// @lc code=end


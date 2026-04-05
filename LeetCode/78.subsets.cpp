/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<int>>&result,vector<int>&path,vector<int>&nums,int startIndex)
    {
        result.push_back(path);
        if(startIndex==nums.size())
        {
            return;
        }
        for(int i=startIndex;i<nums.size();++i)
        {
            path.push_back(nums[i]);
            backtracking(result,path,nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        backtracking(result,path,nums,0);
        return result;        
    }
};
// @lc code=end


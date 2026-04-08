/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
class Solution {
public:
    void backtracking(int startIndex,const vector<int>&nums,vector<vector<int>>&result,vector<int>&path)
    {
        if(path.size()>=2)
        {
            result.push_back(path);
        }
        unordered_set<int>uset;
        for(int i=startIndex;i<nums.size();++i)
        {
            if((path.size()>0&&nums[i]<path[path.size()-1]) || uset.find(nums[i])!=uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(i+1,nums,result,path);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>path;
        backtracking(0,nums,result,path);
        return result;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    void backtracking(int startIndex,vector<vector<int>>&result,vector<int>&path,const vector<int>&nums)
    {
        result.push_back(path);
        for(int i=startIndex;i<nums.size();++i)
        {
            if(i>startIndex&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(i+1,result,path,nums);
            path.pop_back(  );
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        backtracking(0,result,path,nums);
        return result;        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    void func(vector<int>& candidates,int target,int index,vector<int>&path,vector<vector<int>>&result)
    {
        if(target==0)
        {
           result.push_back(path);
           return; 
        }
        for(int i=index;i<candidates.size();++i)
        {
            if(candidates[i]>target)
            {
                break;
            }
            if(i>index && candidates[i]==candidates[i-1])
            {
                continue;
            }
            path.push_back(candidates[i]);
            func(candidates,target-candidates[i],i+1,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,path,result);
        return result;
    }
};
// @lc code=end


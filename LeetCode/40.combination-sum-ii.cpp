/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>result;
    vector<int>v;
    void func(vector<int>& candidates,int target,int i)
    {
        if(target==0)
        {
           result.push_back(v);
           return; 
        }
        if(target<0)
        {
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]>target)
            {
                return; 
            }
            if(j>i && candidates[j]==candidates[j-1])
            {
                continue;
            }
            v.push_back(candidates[j]);
            func(candidates,target-candidates[j],j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        v.clear();
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0);
        return result;
    }
};
// @lc code=end


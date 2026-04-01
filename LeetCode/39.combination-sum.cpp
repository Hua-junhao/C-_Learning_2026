 /*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    void func(vector<int>& candidates,int target,int startIndex,vector<int>&path,vector<vector<int>>&result)
    {
        if(target==0)
        {
           result.push_back(path);
           return; 
        }
        for(int i=startIndex;i<candidates.size();++i)
        {
            if(candidates[i]>target)
            {
                break; 
            }
            path.push_back(candidates[i]);
            func(candidates,target-candidates[i],i,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,path,result);
        return result;
    }
};
// @lc code=end


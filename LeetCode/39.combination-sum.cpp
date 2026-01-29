 /*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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
            v.push_back(candidates[j]);
            func(candidates,target-candidates[j],j);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0);
        return result;
    }
};
// @lc code=end


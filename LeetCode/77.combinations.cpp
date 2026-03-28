/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    void backtracking(int n,int k,int s,vector<int>&path,vector<vector<int>>result)
    {
        if(path.size()==k)
        {
            result.push_back(path);
            return;
        }
        for(int i=s;i <= n - (k - path.size()) + 1;i++)
        {
            path.push_back(i);
            backtracking(n,k,i+1,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        vector<vector<int>>result;
        backtracking(n,k,1,path,result);
        return result;
    }
};
// @lc code=end


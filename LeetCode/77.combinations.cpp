/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
private:
    vector<int>path;
    vector<vector<int>>result;
public:
    void backtracking(int n,int k,int s)
    {
        if(path.size()==k)
        {
            result.push_back(path);
            return;
        }
        for(int i=s;i<=n;i++)
        {
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};
// @lc code=end


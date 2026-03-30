/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    void backtracking(int k,int n,int start,int sum,vector<int>&path,vector<vector<int>>&result)
    {
        if(path.size()==k)
        {
            if(sum==n) 
            {
                result.push_back(path);
            }
            return;
        }
        for(int i=start;i<=9-(k-path.size())+1;++i)
        {
            if(sum+i>n) return;
            path.push_back(i);
            sum+=i;
            backtracking(k,n,i+1,sum,path,result);
            path.pop_back();
            sum-=i;
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        vector<vector<int>>result;
        int sum=0;
        backtracking(k,n,1,sum,path,result);
        return result;
      
    }
};
// @lc code=end


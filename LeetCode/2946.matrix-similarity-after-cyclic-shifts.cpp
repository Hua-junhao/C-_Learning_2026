/*
 * @lc app=leetcode id=2946 lang=cpp
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        k=k%n;
        if(k==0) return true;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=mat[i][(j+k)%n]) return false;
            }
        }
        return true;       
    }
};
// @lc code=end


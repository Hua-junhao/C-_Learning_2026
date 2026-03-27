/*
 * @lc app=leetcode id=2946 lang=cpp
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
class Solution {
public:
    bool shifts(vector<int>&v,int k)
    {
        int n=v.size();
        int l=0,r=k;
        while(l<n)
        {
            if(v[l]!=v[r]) return false;
            l++;
            r=(r+1)%n;
        }
        return true;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        k=k%n;
        if(k==0) return true;
        for(int i=0;i<m;i++)
        {
            if(!shifts(mat[i],k)) return false;
        }
        return true;       
    }
};
// @lc code=end


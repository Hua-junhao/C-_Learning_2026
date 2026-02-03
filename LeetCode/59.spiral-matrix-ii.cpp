/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int rmax=n-1,cmax=n-1;
        int pown=n*n;
        int r=0,c=0;
        int k=0;
        for(int i=1;i<=pown;i++)
        {
            result[r][c]=i;
            if(r==k&&c<cmax-k)
            {
                c++;
            }
            else if(r<rmax-k&&c==cmax-k)
            {
                r++;
            }
            else if(r==rmax-k&&c>k)
            {
                c--;
            }
            else if(r>k+1&&c==k)
            {
                r--;
            }
            else if(r==k+1&&c==k)
            {
                k++;
                c++;
            }
        }
        return result;
        
    }
};
// @lc code=end


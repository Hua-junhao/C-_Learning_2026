/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    void backtracking(int n,int row,vector<string>&chessboard,vector<vector<string>>&result,bool col[], bool diag1[], bool diag2[])
    {
        if(row==n)
        {
            result.push_back(chessboard);
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(col[i] || diag1[row + i] || diag2[row - i + n - 1]) continue;
            col[i] = diag1[row + i] = diag2[row - i + n - 1] = true;
            chessboard[row][i]='Q';
            backtracking(n,row+1,chessboard,result,col,diag1,diag2);
            chessboard[row][i]='.'; 
            col[i] = diag1[row + i] = diag2[row - i + n - 1] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard(n,string(n,'.'));
        vector<vector<string>>result;
        bool col[20] = {false};
        bool diag1[20] = {false};
        bool diag2[20] = {false};
        backtracking(n,0,chessboard,result,col,diag1,diag2);
        return result;
        
    }
};
// @lc code=end


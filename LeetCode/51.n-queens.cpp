/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    bool isValid(const vector<string>&chessboard,int row,int column,int n)
    {
        for(int i=0;i<row;++i)
        {
            if(chessboard[i][column]=='Q') return false;
        }
        for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--)
        {
            if(chessboard[i][j]=='Q') return false;
        }
        for(int i=row-1,j=column+1;i>=0&&j<n;i--,j++)
        {
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }
    void backtracking(int n,int row,vector<string>&chessboard,vector<vector<string>>&result)
    {
        if(row==n)
        {
            result.push_back(chessboard);
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(!isValid(chessboard,row,i,n)) continue;
            chessboard[row][i]='Q';
            backtracking(n,row+1,chessboard,result);
            chessboard[row][i]='.'; 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard(n,string(n,'.'));
        vector<vector<string>>result;
        backtracking(n,0,chessboard,result);
        return result;
        
    }
};
// @lc code=end


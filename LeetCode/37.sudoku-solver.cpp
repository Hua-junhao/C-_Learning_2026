/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
        bool backtracking(vector<vector<char>>&board)
        {
            for(int i=0;i<board.size();++i)
            {
                for(int j=0;j<board[0].size();++j)
                {
                    if(board[i][j]!='.') continue;
                    for(char k='1';k<='9';k++)
                    {
                        if(isValid(i,j,k,board)) 
                        {
                            board[i][j]=k;
                            if(backtracking(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
            return true;
        }
        bool isValid(int r,int c,char k,const vector<vector<char>>&board)
        {
            for(int i=0;i<board[0].size();++i)
            {
                if(board[r][i]==k) return false;
            }
            for(int i=0;i<board.size();++i)
            {
                if(board[i][c]==k) return false;
            }
            r=(r/3)*3,c=(c/3)*3;
            for(int i=r;i<r+3;++i)
            {
                for(int j=c;j<c+3;++j)
                {
                    if(board[i][j]==k) return false;
                }
            }
            return true;
        }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end


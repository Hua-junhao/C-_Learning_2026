/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
        bool backtracking(vector<vector<char>>&board,bool row[9][10],bool col[9][10],bool block[3][3][10])
        {
            for(int i=0;i<9;++i)
            {
                for(int j=0;j<9;++j)
                {
                    if(board[i][j]!='.') continue;
                    for(char k='1';k<='9';k++)
                    {
                        if(!row[i][k-'0'] && !col[j][k-'0'] && !block[i/3][j/3][k-'0']) 
                        {
                            board[i][j]=k;
                            row[i][k-'0']=col[j][k-'0']=block[i/3][j/3][k-'0']=true;
                            if(backtracking(board,row,col,block)) return true;
                            board[i][j]='.';
                            row[i][k-'0']=col[j][k-'0']=block[i/3][j/3][k-'0']=false; 
                        }
                    }
                    return false;
                }
            }
            return true;
        }
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10]={false};
        bool col[9][10]={false};
        bool block[3][3][10]={false};
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    block[i/3][j/3][num] = true;
                }
            }
        }
        backtracking(board,row,col,block);
    }
};
// @lc code=end


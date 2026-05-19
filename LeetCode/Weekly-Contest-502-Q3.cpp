class Solution {
public:
    bool isValid(const vector<vector<int>>&matrix,int row,int col,int x,int n1,int n2,const vector<pair<int,int>>&max_coords)
    {
        int r1=max(0,row-x);
        int r2=min(n1-1,row+x);
        int c1=max(0,col-x);
        int c2=min(n2-1,col+x);
        for (auto& p : max_coords) 
        {
            int i = p.first;
            int j = p.second;
            if (i >= r1 && i <= r2 && j >= c1 && j <= c2) 
            {
                if (!((i == row + x || i == row - x) && (j == col + x || j == col - x))) {
                    return false;
                } 
            }
        }
        for(int i=r1;i<=r2;++i)
        {
            for(int j=c1;j<=c2;++j)
            {
                if(matrix[i][j]>x) 
                {
                    if((i==row+x||i==row-x)&&(j==col+x||j==col-x)) continue;
                    return false;
                }
            }
        }
        return true;
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n1=matrix.size();
        int n2=matrix[0].size();
        int result=0;
        int maxnum=0;
        vector<pair<int, int>> max_coords;
        for(int i=0; i<n1; ++i)
        {
            for(int j=0; j<n2; ++j)
            {
                maxnum=max(maxnum,matrix[i][j]);
            }
        }   
        if(maxnum>0){
            for(int i=0; i<n1; ++i)
            {
            for(int j=0; j<n2; ++j)
            {
                if (matrix[i][j] == maxnum) max_coords.push_back({i, j});
            }
            }
        }   
        for(int i=0;i<n1;++i)
        {
            for(int j=0;j<n2;++j)
            {
                if(matrix[i][j]>0)
                {
                    if(matrix[i][j]==maxnum||isValid(matrix,i,j,matrix[i][j],n1,n2,max_coords)) result++;
                }
                
            }
        }
        return result;

    }
};©leetcode
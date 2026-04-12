class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>result;
        result.resize(matrix.size());
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.size();++j)
            {
                if(matrix[i][j]==1) result[i]++;
            }
        }
        return result;
        
    }
};©leetcode
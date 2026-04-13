class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> result(matrix.size(), 0);
        for(int i=0;i<matrix.size();++i)
        {
            result[i] = count(matrix[i].begin(), matrix[i].end(), 1); 
        }
        return result;
        
    }
};©leetcode
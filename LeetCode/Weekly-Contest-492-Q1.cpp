class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int minindex=-1;
        for(int i=0;i<n;i++)
        {
            if(capacity[i]<itemSize) continue;
            if(minindex==-1||capacity[i]<capacity[minindex]) minindex=i;
        }
        return minindex;
        
    }
};©leetcode
/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
        int n=intervals.size();
        if(n==0) return 0;
        int count=1;
        int right=intervals[0][1];
        for(int i=0;i<n;++i)
        {
            if(right<=intervals[i][0])
            {
                right=intervals[i][1];
                count++;
            }
        }
        return n-count;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1) return 0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
        int count=1;
        int right=intervals[0][1];
        for(int i=1;i<n;++i)
        {
            const auto& interval=intervals[i];
            if(right<=interval[0])
            {
                right=interval[1];
                count++;
            }
        }
        return n-count;
        
    }
};
// @lc code=end


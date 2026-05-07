/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
        int n=intervals.size();
        vector<vector<int>>result;
        result.reserve(n);
        result.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;--i)
        {
            if(result.back()[0]<=intervals[i][1])
            {
                result.back()[0]=min(intervals[i][0],result.back()[0]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
// @lc code=end


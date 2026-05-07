/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});
        int n=intervals.size();
        vector<vector<int>>result;
        result.reserve(n);
        result.push_back(intervals[0]);
        for(int i=1;i<n;++i)
        {
            const auto& interval = intervals[i];
            if(result.back()[1]>=interval[0])
            {
                result.back()[1]=max(interval[1],result.back()[1]);
            }
            else
            {
                result.push_back(interval);
            }
        }
        return result;
        
    }
};
// @lc code=end


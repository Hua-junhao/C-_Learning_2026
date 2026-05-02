/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=1) return n;
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});
        int result=1;
        for(int i=1;i<n;++i)
        {
            if(points[i][0]>points[i-1][1]) result++;  
            else points[i][1]=min(points[i][1],points[i-1][1]);
        }
        return result;
        
    }
};
// @lc code=end


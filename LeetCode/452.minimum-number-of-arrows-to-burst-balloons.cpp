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
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
        int result=1;
        int arrow_pos=points[0][1];
        for(int i=1;i<n;++i)
        {
            const auto& balloon = points[i]; 
            if (balloon[0] > arrow_pos) {
                result++;
                arrow_pos = balloon[1];
            }
        }
        return result;
        
    }
};
// @lc code=end


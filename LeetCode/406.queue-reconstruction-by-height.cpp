/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        if(a[0]==b[0]) return a[1]<b[1];//身高相同，前人少在前
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>que;
        int n=people.size();
        for(int i=0;i<n;++i)
        {
            int position=people[i][1];
            que.insert(que.begin()+position,people[i]);
        }
        return que;
        
    }
};
// @lc code=end


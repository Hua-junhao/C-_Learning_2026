/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        list<vector<int>>que;
        for(const auto&person:people)
        {
            int position=person[1];
            auto it= que.begin();
            advance(it,position);
            que.insert(it,person);
        }
        return vector<vector<int>>(que.begin(),que.end());
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
    int left =0;
    int v=0;
    int right =height.size()-1;
    while (left<right)
    {
        int v1=min(height[left],height[right])*(right-left);
        if(v1>v) v=v1;
        if(height[left]>height[right]) right--;
        else left++;
    }
    return v;
    }
};
// @lc code=end


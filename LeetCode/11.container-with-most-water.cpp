/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
    int v=0;
    for (int left=0;left<height.size()-1;left++)
    {   
        int right=height.size()-1;
        while (right>left)
        {
            int v1=min(height[left],height[right])*(right-left);
            if(v1>v) v=v1;
            right--;
        }
    }
      return v;  
    }
};
// @lc code=end


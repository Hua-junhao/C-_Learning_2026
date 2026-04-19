/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdis=0,i=0,j=0;
        int m=nums1.size(),n=nums2.size();
        while(i<m&&j<n)
        {
            if(nums2[j]>=nums1[i])
            {
                maxdis=max(maxdis,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return maxdis;
    }
};
// @lc code=end


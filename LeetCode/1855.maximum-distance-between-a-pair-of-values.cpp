/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxdis=0,i=nums1.size()-1,j=nums2.size()-1;
        if(j<i) i=j;
        while(i>=0&&j>=0)
        {
            while(i>=0&&j>=0&&(nums1[i]>nums2[j]||i>j))
            {
                j--;
                if(j<i) i=j;
                if(j<0) break;
            }
            while(i>0&&nums1[i-1]<=nums2[j]) i--;
            if(maxdis<j-i) maxdis=j-i;
            i--;
            j--;
        }
        return maxdis;
    }
};
// @lc code=end


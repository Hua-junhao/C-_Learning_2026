/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        int m1,m2;
        if ((m+n)%2==1)
        {
            m1=(m+n)/2;
            m2=(m+n)/2;
        }
        else
        {
            m1=(m+n)/2-1;
            m2=(m+n)/2;
        }
        vector <int>nums3;
        int s1=0,s2=0;
        int total =m+n;
        while (total--)
        {
            if(s1==m) 
            {
                nums3.push_back(nums2[s2]);
                s2++;
            }
            else if(s2==n) 
            {
                nums3.push_back(nums1[s1]);
                s1++;
            }
            else if(nums1[s1]>nums2[s2]) 
            {
                nums3.push_back(nums2[s2]);
                s2++;
            }
            else 
            {
                nums3.push_back(nums1[s1]);
                s1++;
            }
        }
       double a=(nums3[m1]+nums3[m2])/2.0;
       return a; 
    }
};
// @lc code=end


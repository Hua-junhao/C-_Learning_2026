/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        int nums[1001]={0};
        for(int i:nums1)
        {
            nums[i]=1;
        }  
        for(int i:nums2)
        {
            if(nums[i]==1)
            {
                result.push_back(i);
                nums[i]=0;
            }
        }
        return result;
    }
};
// @lc code=end


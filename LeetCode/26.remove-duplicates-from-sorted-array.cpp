/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        unordered_set<int>uset;
        for(int i=0;i<nums.size();i++)
        {
            if(uset.find(nums[i])==uset.end())
            {
                nums[l]=nums[i];
                l++;
                uset.insert(nums[i]);
            }
        }
        return l;
    }
};
// @lc code=end


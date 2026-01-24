/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1])//递减数列，因此只要nums[i]<nums[i+1]及是第一个后面有比它大的数的位置
        {
            i--;
        }
        if(i>=0)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    swap(nums[i],nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i+1,nums.end());//翻转，使i之后最小排列(i位(高位)变大就必然大)
    }
};
// @lc code=end


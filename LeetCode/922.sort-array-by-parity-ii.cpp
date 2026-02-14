/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1;
        int n=nums.size();
        while(i<n-1)
        {
            if(i%2==nums[i]%2)
            {
                i++;
                j=i+1;
            }
            else
            {
                while(nums[j]%2!=i%2)
                {
                    j++;
                }
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};
// @lc code=end


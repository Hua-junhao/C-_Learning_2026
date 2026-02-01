/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1,k=r;
        vector<int>result(r+1);
        while(k>=0)
        {

            if(pow(nums[r],2)<pow(nums[l],2)){
                result[k]=pow(nums[l],2);
                l++;
            }
            else
            {
                result[k]=pow(nums[r],2);
                r--;
            }
            k--;
        }
        return result;
    }
};
// @lc code=end


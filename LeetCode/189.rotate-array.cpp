/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>result;
        int j=(n-k)%n,i=(j+1)%n;
        if(j==0)
        {
            return;
        }
        result.push_back(nums[j]);
        while(i!=j)
        {
            result.push_back(nums[i]);
            i=(i+1)%n;
        }
        nums=result;
        
    }
};
// @lc code=end


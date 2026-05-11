/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s="";
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            s+=to_string(nums[i]);
        }
        vector<int>result;
        for(char c:s)
        {
            result.push_back(c-'0');
        }
        return result;
        
    }
};
// @lc code=end


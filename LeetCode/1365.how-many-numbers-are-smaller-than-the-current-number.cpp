/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v=nums;
        vector<int> result;
        sort(v.begin(),v.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int k=nums.size()-1;
            while(k>=0&&nums[i]<=v[k])
            {
                k--;
            }
            result.push_back(k+1);
        }
        return result;
        
    }
};
// @lc code=end


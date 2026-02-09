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
        sort(v.begin(),v.end());
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(map.find(v[i])==map.end())
            {
                map[v[i]]=i;
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            result.push_back(map[nums[i]]);
        }
        return result;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set;
        for(int i:nums1)
        {
            set.insert(i);
        }   
        unordered_set<int>set2;     
        vector<int>result;
        for(int i:nums2)
        {
            if(set.find(i)!=set.end())
            {
                set2.insert(i);
            }
        }
        for(int i:set2)
        {
            result.push_back(i);
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        int n=nums1.size();
        unordered_map<int,int>map;
        map.reserve(n*n);
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                int sum=i+j;
                map[sum]++;
            }
        }
        for(int i:nums3)
        {
            for(int j:nums4)
            {
                int sum=-i-j;
                auto it=map.find(sum);
                if(it!=map.end())
                {
                    count+=it->second;
                }
            }
        }
        return count;
        
    }
};
// @lc code=end


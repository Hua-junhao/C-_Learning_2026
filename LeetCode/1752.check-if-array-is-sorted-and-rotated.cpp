/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        int min_index=0;
        int n=nums.size();
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[min_index]) min_index=i;
        }
        int cur=min_index;
        int next=(cur+1)%n;
        while(next!=min_index)
        {
            if(nums[cur]>nums[next]) 
            {
                if(!(nums[next]==nums[min_index]&&nums[(next+1)%n]==nums[min_index])) return false;
            }
            cur=next;
            next=(next+1)%n;
        }
        return true;
        
    }
};
// @lc code=end


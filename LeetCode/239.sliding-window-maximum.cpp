/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(!dq.empty()&&nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front()<=i-k)
            {
                dq.pop_front();
            }
            if(i>=k-1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
// @lc code=end


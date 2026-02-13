 /*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int lsum=0,rsum=0;
            int l=0,r=n-1;
            while(l<i)
            {
                lsum+=nums[l];
                l++;
            }
            while(r>i)
            {
                rsum+=nums[r];
                r--;
            }
            if(lsum==rsum)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return maxUncrossedLines(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        vector<int>dp(m+1);
        for(int i=1;i<=n;++i)
        {
            int pre=0;
            for(int j=1;j<=m;++j)
            {
                int temp=dp[j];
                if(nums1[i-1]==nums2[j-1])  dp[j]=pre+1;
                else dp[j]=max(dp[j-1],dp[j]);
                pre=temp;
            }
        }
        return dp[m];

    }
};
// @lc code=end


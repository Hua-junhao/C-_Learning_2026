/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int maxlen=0;
        vector<vector<int>>dp(n+1,vector(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]!=nums2[j-1]) continue;
                dp[i][j]=dp[i-1][j-1]+1;
                maxlen=max(maxlen,dp[i][j]);
            }
        }
        return maxlen;
    }
};
// @lc code=end


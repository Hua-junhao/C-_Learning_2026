class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        if(sum%2==1) return false;
        sum/=2;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(sum+1,0);
        for(int i=0;i<n;++i)
        {
            for(int j=sum;j>=nums[i];--j)
            {
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        return dp[sum]==sum;
        
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<int>dp(target+1,0);
        for(int num:nums)
        {
            if(num>target) return false;
            for(int j=target;j>=num;--j)
            {
                dp[j]=max(dp[j],dp[j-num]+num);
            }
            if(dp[target]==target) return true;
        }
        return dp[target]==target;
        
    }
};
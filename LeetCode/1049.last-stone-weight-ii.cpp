class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i:stones)
        {
            sum+=i;
        }
        int target=sum/2;
        vector<int>dp(target+1,0);
        for(int num:stones)
        {
            if(num>target) continue;
            for(int j=target;j>=num;--j)
            {
                dp[j]=max(dp[j],dp[j-num]+num);
            }
        }
        return sum-dp[target]*2;
        
    }
};
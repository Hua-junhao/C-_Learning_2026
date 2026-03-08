class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        long long sum=0,product=1;
        if(n==1) return -1;
        long long max=n*pow(10,9);
        for(int i=0;i<n-1;i++)
        {
            sum+=nums[i];
        }
        if(sum==1) index=n-1;
        for(int i=n-2;i>0;i--)
        {
            if(product > max/nums[i+1]) break;
            product=product*nums[i+1];
            sum-=nums[i];
            if(product>sum) break;
            if(sum==product) index=i;
        }
        return index;
    }
};©leetcode
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return n;
        vector<int>diff(n-1);
        for(int i=0;i<n-1;i++)
        {
            diff[i]=nums[i+1]-nums[i];
        }
        vector<int>left_len(n-1,1),right_len(n-1,1);
        int m=n-1;
        for(int i=1;i<m;i++)
        {
            if(diff[i]==diff[i-1]) left_len[i]=left_len[i-1]+1;
        }
        for(int i=m-2;i>=0;i--)
        {
            if(diff[i]==diff[i+1]) right_len[i]=right_len[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<m;i++) 
        {
            ans=max(ans,left_len[i]+1);
            ans=max(ans, right_len[i] + 1);
        }
        for(int i=0;i<m-1;i++)
        {
            if ((diff[i] + diff[i+1]) % 2 == 0) {
                int d = (diff[i] + diff[i+1]) / 2;
                int current_len = 2; 
                if (i > 0 && diff[i-1] == d) current_len += left_len[i-1];
                if (i < m - 2 && diff[i+2] == d) current_len += right_len[i+2];
                ans=max(ans,current_len);
            }
        }
        return min(n,ans+1);
    }
};©leetcode
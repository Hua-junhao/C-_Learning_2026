#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<vector<int>>dp(n,vector<int>(v+1,0));
    vector<int>weight(n,0);
    vector<int>value(n,0);
    for(int i=0;i<n;++i)
    {
        cin>>weight[i]>>value[i];
    }
    for(int i=weight[0];i<=v;++i)
    {
        dp[0][i]=value[0]*(i/weight[0]);
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=v;j++)
        {
            if(j<weight[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
        }
    }
    cout<<dp[n-1][v]<<endl;
    return 0;

}
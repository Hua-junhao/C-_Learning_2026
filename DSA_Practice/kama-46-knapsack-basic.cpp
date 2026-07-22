#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,N;
    cin>>M>>N;
    vector<int>weight(M,0);
    vector<int>value(M,0);
    for(int i=0;i<M;++i)
    {
        cin>>weight[i];
    }
    for(int i=0;i<M;++i)
    {
        cin>>value[i];
    }
    vector<vector<int>>dp(M,vector<int>(N+1,0));
    for(int i=weight[0];i<=N;++i)
    {
        dp[0][i]=value[0];
    }
    for(int i=1;i<M;++i)
    {
        for(int j=0;j<N+1;++j)
        {
            if(j>=weight[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[M-1][N]<<endl;
    return 0;
}
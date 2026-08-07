#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m && j<=i;++j)
        {
            dp[i]+=dp[i-j];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
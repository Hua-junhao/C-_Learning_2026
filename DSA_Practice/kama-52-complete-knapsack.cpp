#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<int>dp(v+1,0);
    vector<int>weight(n,0);
    vector<int>value(n,0);
    for(int i=0;i<n;++i)
    {
        cin>>weight[i]>>value[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=weight[i];j<=v;++j)
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[v]<<endl;
    return 0;

}
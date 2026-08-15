#include<bits/stdc++.h>
using namespace std;
int main(){
    int C,N;
    cin>>C>>N;
    vector<int>dp(C+1,0);
    vector<int>raw_weights(N);
    vector<int>raw_values(N);
    vector<int>numbers(N);
    for(int i=0;i<N;++i) cin>>raw_weights[i];
    for(int i=0;i<N;++i) cin>>raw_values[i];
    for(int i=0;i<N;++i) cin>>numbers[i];
    vector<int> weights,values;
    for(int i=0;i<N;++i)
    {
        int count=numbers[i];
        for(int k=1;k<=count;k*2)
        {
            weights.push_back(raw_weights[i]*k);
            values.push_back(raw_values[i]*k);
            count-=k;
        }
        if(count>0)
        {
            weights.push_back(raw_weights[i]*count);
            values.push_back(raw_values[i]*count);
        }
    }
    int n=weights.size();
    for(int i=0;i<n;++i)
    {
        for(int j=C;j>=weights[i];--j)
        {
            dp[j]=max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;

}
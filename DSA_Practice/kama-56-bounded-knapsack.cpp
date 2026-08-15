#include<bits/stdc++.h>
using namespace std;
int main(){
    int C,N;
    cin>>C>>N;
    vector<int>dp(C+1,0);
    vector<int>weights(N);
    vector<int>values(N);
    vector<int>numbers(N);
    for(int i=0;i<N;++i) cin>>weights[i];
    for(int i=0;i<N;++i) cin>>values[i];
    for(int i=0;i<N;++i) cin>>numbers[i];
    for(int i=0;i<N;++i)
    {
        for(int j=C;j>=weights[i];--j)
        {
            for(int k=1;k<=numbers[i] && j-weights[i]*k>=0;++k)
            {
                dp[j]=max(dp[j],dp[j-weights[i]*k]+values[i]*k);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;

}
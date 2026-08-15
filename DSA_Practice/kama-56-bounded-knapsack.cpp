#include<bits/stdc++.h>
using namespace std;
int main(){
    int C,N;
    cin>>C>>N;
    vector<int>dp(C+1,0);
    vector<int>weights(N),values(N),numbers(N);
    for(int i=0;i<N;++i) cin>>weights[i];
    for(int i=0;i<N;++i) cin>>values[i];
    for(int i=0;i<N;++i) cin>>numbers[i];
    for (int i = 0; i < N; ++i) {
        int w = weights[i];
        int v = values[i];
        int num = numbers[i];
        if (w * num >= C) {
            for (int j = w; j <= C; ++j) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        } 
        else {
            for (int j = C; j >= w; --j) {
                int kw = w;
                int kv = v;
                for (int k = 1; k <= num && kw <= j; ++k, kw += w, kv += v) {
                    dp[j] = max(dp[j], dp[j - kw] + kv);
                }
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;

}
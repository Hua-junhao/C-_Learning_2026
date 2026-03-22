class Solution {
public:
    long long countCommas(long long n) {
        long long k=0;
        long long num=1000;
        while(n>=num)
        {
            k+=n-num+1;
            num=num*1000;
        }
        return k;
    }
};©leetcode
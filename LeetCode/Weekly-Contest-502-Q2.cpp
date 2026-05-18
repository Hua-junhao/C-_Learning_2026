class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        long long left = round(pow(l, 1.0 / k));
        long long right = round(pow(r, 1.0 / k));
        while(pow(left,k)<l) left++;
        while(pow(right,k)>r) right--;
        return (right >= left) ? (right - left + 1) : 0;    

    }
};©leetcode
/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long  left=1,right=x;
        int result,mid;
        if(x==0||x==1) return x;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid==x/mid) return mid;
            else if(mid>x/mid) right=mid-1;
            else
            {
                left=mid+1;
                result=mid;
            }
        }
        return result;
    }
};
// @lc code=end


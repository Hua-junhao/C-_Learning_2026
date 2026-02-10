/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        if(n<3)
        {
            return false;
        }
        while(l<r&&arr[l]<arr[l+1])
        {
            l++;
        }
        while(r>l&&arr[r]<arr[r-1])
        {
            r--;
        }
        if(l==0||r==n-1||l!=r)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool flag=1,flag2=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            {
                return false;
            }
            if(flag&&arr[i]>arr[i-1])
            {
                flag2=0;
                continue;
            }
            if(flag&&arr[i]<arr[i-1])
            {
                flag=0;
                continue;
            }
            if(flag==0&&arr[i]>arr[i-1])
            {
                return false; 
            }
            if(flag==0&&arr[i]<arr[i-1])
            {
                continue;
            }
        }
        if(flag||flag2)
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


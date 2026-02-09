/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       int a[101]={0};
       int n=nums.size();
       for(int i:nums)
       {
            a[i]++;
       }
       for(int i=1;i<101;i++)
       {
            a[i]+=a[i-1];
       }
       vector<int>result;
       for(int i:nums)
       {
            if(i==0)
            {
               result.push_back(0);
               continue;  
            }
            result.push_back(a[i-1]);
       }
       return result;
        
    }
};
// @lc code=end


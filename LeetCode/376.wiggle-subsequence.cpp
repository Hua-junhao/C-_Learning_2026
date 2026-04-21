/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        int curdiff=0,prediff=0,result=1;
        for(int i=0;i<n-1;i++)
        {
            curdiff=nums[i+1]-nums[i];
            if(curdiff>0&&prediff<=0 || prediff>=0&&curdiff<0)
            {
                result++;
                prediff=curdiff;
            }   
        }
        return result;
        
    }
};
// @lc code=end


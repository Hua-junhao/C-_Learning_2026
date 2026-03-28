/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9)
        {
            digits[n-1]++;
            return digits;
        }
        int i=n-1;
        while(i>=0)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                digits[i+1]=0;
                return digits;
            }
            digits[i]=0;
            i--;
        }
        vector<int>v(n+1,0);
        v[0]=1;
        return v;
        
    }
};
// @lc code=end


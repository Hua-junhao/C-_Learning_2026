/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0,n=prices.size();
        for(int i=1;i<n;++i)
        {
            result+=max(prices[i]-prices[i-1],0);
        }
        return result;
        
    }
};
// @lc code=end


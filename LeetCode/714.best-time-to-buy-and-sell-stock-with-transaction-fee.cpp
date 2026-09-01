/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=-prices[0];
        int sold=0;
        for(int price:prices)
        {
            buy=max(buy,sold-price);
            sold=max(sold,buy+price-fee);
        }
        return sold;
        
    }
};
// @lc code=end


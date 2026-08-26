/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1=-prices[0];
        int sold1=0;
        int hold2=-prices[0];
        int sold2=0;
        for(int price:prices)
        {
            hold1=max(hold1,-price);
            sold1=max(sold1,hold1+price);
            hold2=max(hold2,sold1-price);
            sold2=max(sold2,hold2+price);
        }
        return sold2;
    }
};
// @lc code=end


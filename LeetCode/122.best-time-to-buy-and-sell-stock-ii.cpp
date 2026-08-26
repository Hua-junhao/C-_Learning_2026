/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=-prices[0];
        int sold=0;
        for(int price:prices)
        {
            hold=max(hold,sold-price);
            sold=max(sold,hold+price);
        }
        return sold;
        
    }
};
// @lc code=end


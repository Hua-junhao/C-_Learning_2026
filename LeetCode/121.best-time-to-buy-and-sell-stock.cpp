/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX,result=0;
        for(int price:prices)
        {
            low=min(low,price);
            result=max(result,price-low);
        }
        return result;
        
    }
};
// @lc code=end


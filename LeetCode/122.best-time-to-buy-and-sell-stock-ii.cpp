/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        int hold=-prices[0];
        int sold=0;
        for(int i=1;i<n;++i)
        {
            int new_hold=max(hold,sold-prices[i]);
            int new_sold=max(sold,hold+prices[i]);
            hold=new_hold;
            sold=new_sold;
        }
        return sold;
        
    }
};
// @lc code=end


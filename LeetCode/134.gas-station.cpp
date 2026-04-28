/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_sum = 0,total_sum = 0,start_index = 0,n=gas.size();
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            current_sum += diff;
            total_sum += diff;
            if (current_sum < 0) {
                start_index = i + 1; 
                current_sum = 0;     
            }
        }
        if (total_sum < 0) return -1;
        return start_index;

    }
};
// @lc code=end


/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;++i)
        {
            int rest=gas[i]-cost[i];
            int index=(i+1)%n;
            while(rest>=0 && index!=i)
            {
                rest+=gas[index]-cost[index];
                index=(index+1)%n;
            }
            if(rest>=0 && index==i) return i;
        }
        return -1;
        
    }
};
// @lc code=end


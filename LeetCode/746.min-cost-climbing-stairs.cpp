class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre_cost=0;
        int cur_cost=0;
        int n=cost.size();
        if(n<=1) return 0;
        for(int i=2;i<=n;++i)
        {
            int next_cost=min(pre_cost+cost[i-2],cur_cost+cost[i-1]);
            pre_cost=cur_cost;
            cur_cost=next_cost;
        }
        return cur_cost;
        
    }
};
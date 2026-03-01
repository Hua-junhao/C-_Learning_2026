class Solution {
public:
    int minCost(int n) {
        if(n==1)
        {
            return 0;
        }
        if(n==2)
        {
            return 1;
        }
        else if(n==3)
        {
            return 3;
        }
        else 
        {
            return minCost(n/2)+minCost(n-n/2)+(n/2)*(n-n/2);
        }    
    }
};
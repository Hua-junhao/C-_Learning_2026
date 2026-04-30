/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[2]={0};
        for(int i:bills)
        {
            if(i==5)
            {
                arr[0]++;
            }
            else if(i==10)
            {
                if(arr[0]>0)
                {
                    arr[1]++;
                    arr[0]--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(arr[1]>0 && arr[0]>0)
                {
                    arr[0]--;
                    arr[1]--;
                    continue;
                }
                else if(arr[0]>2)
                {
                    arr[0]-=3;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


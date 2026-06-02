/*
 * @lc app=leetcode id=3633 lang=cpp
 *
 * [3633] Earliest Finish Time for Land and Water Rides I
 */

// @lc code=start
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int result=INT_MAX;
        for(int i=0;i<n;++i)
        {
            int ls=landStartTime[i];
            int ld=landDuration[i];
            for(int j=0;j<m;++j)
            {
                int ws=waterStartTime[j];
                int wd=waterDuration[j];
                if(ls<ws)
                {
                    result=min(result,max(ls+ld,ws)+wd);
                }
                else 
                {
                    result=min(result,max(ws+wd,ls)+ld);
                }
            }
        }
        return result;
        
    }
};
// @lc code=end


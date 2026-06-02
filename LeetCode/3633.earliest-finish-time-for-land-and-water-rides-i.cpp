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
            for(int j=0;j<m;++j)
            {
                if(landStartTime[i]<waterStartTime[j])
                {
                    int time1=landDuration[i]+landStartTime[i];
                    result=min(result,max(time1,waterStartTime[j])+waterDuration[j]);
                }
                else 
                {
                    int time2=waterDuration[j]+waterStartTime[j];
                    result=min(result,max(time2,landStartTime[i])+landDuration[i]);
                }
            }
        }
        return result;
        
    }
};
// @lc code=end


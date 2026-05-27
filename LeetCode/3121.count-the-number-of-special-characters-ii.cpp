/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>state(26,0);
        int count=0;
        for(char c:word)
        {
            if(islower(c))
            {
                int idx=c-'a';
                if(state[idx]==0) state[idx]=1;
                else if(state[idx]==2) state[idx]=-1;
            }
            else
            {
                int idx=c-'A';
                if(state[idx]==1) state[idx]=2;
                else if(state[idx]==0)state[idx]=-1;
            }
        }
        for(int s:state)
        {
            if(s==2) count++;
        }
        return count;
        
    }
};
// @lc code=end


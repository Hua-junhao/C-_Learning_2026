/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>Candy(ratings.size(),1);
        for(int i=1;i<n;++i)
        {
            if(ratings[i]>ratings[i-1]) Candy[i]=Candy[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1]) Candy[i]=max(Candy[i],Candy[i+1]+1);
        }
        int result=0;
        for(int i:Candy)
        {
            result+=i;
        }
        return result;

    }
};
// @lc code=end


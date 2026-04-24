/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int diff=0,m=0;
        for(char c:moves)
        {
            if(c=='L') diff--;
            else if(c=='R') diff++;
            else m++;
        }
        return abs(diff)+m;
        
    }
};
// @lc code=end


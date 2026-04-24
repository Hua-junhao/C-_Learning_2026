/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,m=0;
        for(char c:moves)
        {
            if(c=='L') l++;
            else if(c=='R') r++;
            else m++;
        }
        return abs(l-r)+m;
        
    }
};
// @lc code=end


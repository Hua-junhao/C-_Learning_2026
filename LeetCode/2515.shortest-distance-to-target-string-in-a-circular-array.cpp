/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size(),k=0,l=startIndex,r=startIndex;
        while(k!=n)
        {
            if(words[l]==target||words[r]==target) return k;
            l=(l-1+n)%n;
            r=(r+1)%n;
            k++;
        }
        return -1;
        
    }
};
// @lc code=end


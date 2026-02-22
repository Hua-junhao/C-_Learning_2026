/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(char c:magazine)
        {
            map[c]++;
        }
        for(char c:ransomNote)
        {
            map[c]--;
            if(map[c]<0)
            {
                return false;
            }   
        }
        return true;
        
    }
};
// @lc code=end


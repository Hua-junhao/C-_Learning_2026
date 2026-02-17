/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        if(s.size()!=t.size())
        {
            return false;
        }
        for(char c:s)
        {
            map[c]++;
        }
        for(char c:t)
        {
            if(map.find(c)==map.end()||map[c]<=0)
            {
                return false;
            }
            else
            {
                map[c]--;
            }
        }
        return true;
        
    }
};
// @lc code=end


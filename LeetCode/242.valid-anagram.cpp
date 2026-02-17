/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
        {
            return false;
        }
        int arr[26]={0};
        for(char c:s)
        {
            arr[c-'a']++;
        }
        for (char c:t)
        {
            arr[c-'a']--;
        }        
        for(int i:arr)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


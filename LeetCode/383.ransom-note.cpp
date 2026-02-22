/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        if(ransomNote.size()>magazine.size())
        {
            return false;
        }
        for(char c:magazine)
        {
            arr[c-'a']++;
        }
        for(char c:ransomNote)
        {
            int i=c-'a';
            arr[i]--;
            if(arr[i]<0)
            {
                return false;
            }   
        }
        return true;
        
    }
};
// @lc code=end


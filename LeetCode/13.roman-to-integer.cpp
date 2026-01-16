/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int integer=0;
        unordered_map <char,int>store={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i=0;
        while(i<s.size()-1)
        {
            if(store[s[i+1]]>store[s[i]]) 
            {
                integer+=store[s[i+1]]-store[s[i]];
                i+=2;
            }
            else
            {
                integer+=store[s[i]];
                i++;
            }
        }
        if(i!=s.size()) integer+=store[s[s.size()-1]];
        return integer;
        
    }
};
// @lc code=end


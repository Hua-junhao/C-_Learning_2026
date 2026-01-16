/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
private:
    inline int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        int integer=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int num=getValue(s[i]);
            if(i<n-1&&num<getValue(s[i+1]))  integer-=num;
            else integer+=num;
        }
        return integer;
        
    }
};
// @lc code=end


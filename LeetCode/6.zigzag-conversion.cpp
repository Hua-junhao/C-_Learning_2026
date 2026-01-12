/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> v(numRows);
        if (numRows == 1) return s;//forget this 
        int k=0;
        int m=1;
        for (char c:s)
        {
            v[k]+=c;
            k+=m;
            if (k==numRows-1) m=-1;
            if (k==0) m=1;
        }
        string a;
        for (int i=0;i<numRows;i++)
        {
            a+=v[i];
        }
        return a;
    }
};
// @lc code=end


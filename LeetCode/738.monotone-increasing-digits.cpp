/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int len=s.size();
        int nine_start=len;
        for(int i=len-1;i>0;--i)
        {
            if(s[i-1]>s[i])
            {
                nine_start=i;
                s[i-1]--;
            }
        }
        std::fill(s.begin() + nine_start, s.end(), '9');
        return stoi(s);

    }
};
// @lc code=end


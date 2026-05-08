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
        int N=s.size();
        int flag=N;
        for(int i=N-1;i>0;--i)
        {
            if(s[i-1]>s[i])
            {
                flag=i;
                s[i-1]--;
            }
        }
        for(int i=flag;i<N;++i)
        {
            s[i]='9';
        }
        return stoi(s);

    }
};
// @lc code=end


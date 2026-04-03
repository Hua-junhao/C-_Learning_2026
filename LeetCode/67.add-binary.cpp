/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,carry=0;
        string result="";
        result.reserve(max(a.size(), b.size()) + 1);
        while(i>=0||j>=0||carry>0)
        {
            int sum=carry;
            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';
            carry=sum/2;
            result.push_back((sum%2)+'0');
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
// @lc code=end


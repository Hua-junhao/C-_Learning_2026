/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string& s,int startIndex,int endIndex)
    {
        if(startIndex>endIndex) return false;
        if(startIndex!=endIndex && s[startIndex]=='0') return false;
        int sum=0;
        for(int i=startIndex;i<=endIndex;++i)
        {
            if(!(s[i]<='9' && s[i]>='0')) return false;
            sum=sum*10+s[i]-'0';
            if(sum>255) return false;
        }
        return true;
    }
    void backtracking(int startIndex,int num,string& s,vector<string>&result)
    {
        if(num==3)
        {
            if(isValid(s,startIndex,s.size()-1))
            {
                result.push_back(s);
            }
            return;
        }
        for(int i=startIndex;i<s.size();++i)
        {
            if(isValid(s,startIndex,i))
            {
                s.insert(s.begin()+i+1,'.');
                num++;
                backtracking(i+2,num,s,result);
                num--;
                s.erase(s.begin()+i+1);
            }
            else
            {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        backtracking(0,0,s,result);
        return result;
        
    }
};
// @lc code=end


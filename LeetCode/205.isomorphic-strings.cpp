/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map1;
        unordered_map<char,char>map2;
        int n=s.size();
        if(n!=t.size()) return false;
        for(int i=0;i<n;i++)
        {
            if(map1.find(s[i])==map1.end()&&map2.find(t[i])==map2.end())
            {
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else if(map1[s[i]]==t[i]&&map2[t[i]]==s[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;

    }
};
// @lc code=end


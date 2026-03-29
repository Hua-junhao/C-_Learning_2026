class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=0,n=s.size();
        while(i<n)
        {
            if(s[i]==s[n-i-1]) return i;
            i++;
        }
        return -1;
        
    }
};©leetcode
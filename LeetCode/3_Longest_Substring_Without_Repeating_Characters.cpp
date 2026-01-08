 class Solution {
public:
    bool isdifferent(const string &s,int start,int end)
    {
        for (int i=start;i<end;i++)
        {
            for (int j=i+1;j<=end;j++)
            {
                if (s[j]==s[i]) 
                {
                    return 0;
                }
            }
        }
        return 1;

    }
    int lengthOfLongestSubstring(string s) 
    { 
        int maxlength=1;
        
        if (s.size()==0) return 0;
        for (int i=0;i<s.size();i++)
        {
            for (int j=i+1;j<s.size();j++)
            {
                if (isdifferent(s,i,j))
                {
                    maxlength=max(maxlength,j-i+1);
                }
            }
        }
        return maxlength;
    }
    
};
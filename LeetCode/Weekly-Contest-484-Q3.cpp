class Solution {
private:
    bool is_same(string s1,string s2)
    {
        if (s1.size()!=s2.size()) return 0;
        else
        {
            int n=(s1[0]-s2[0]+26)%26;
            for (int i=1;i<s1.size();i++)
            {
                if( (s1[i]-s2[i]+26)%26!=n)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
public:
    long long countPairs(vector<string>& words) 
    {
        long long n=0;
        for (int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if (is_same(words[i],words[j]))
                {
                    n++;
                }
            } 
        }
        return n;    
    }
};
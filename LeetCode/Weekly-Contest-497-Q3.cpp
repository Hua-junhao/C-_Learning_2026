class Solution {
public:
    int longestBalanced(string s) {
        int num1=0,num2=0;
        for(char c:s)
        {
            if(c=='0') num1++;
            else num2++;
        }
        int sum=0,maxlen=0,n=s.size();
        unordered_map<int,vector<int>>map;
        map[0].push_back(-1); 
        for(int j=0;j<n;++j)
        {
            if(s[j]=='0') sum--;
            else sum++;
            if(map.find(sum)!=map.end())
            {
                maxlen=max(j-map[sum][0],maxlen);
            }
            if(map.find(sum-2)!=map.end())
            {
                for(int idx=0;idx<map[sum-2].size();++idx)
                {
                    if(j-map[sum-2][idx]<=num1*2)
                    {
                        maxlen=max(j-map[sum-2][idx],maxlen);
                        break;
                    }
                }
            }
            if(map.find(sum+2)!=map.end())
            {
                for(int idx=0;idx<map[sum+2].size();++idx)
                {
                    if(j-map[sum+2][idx]<=num2*2)
                    {
                        maxlen=max(j-map[sum+2][idx],maxlen);
                        break;
                    }
                }
            }
            map[sum].push_back(j);
        }
        return maxlen;
    }
};©leetcode
class Solution {
public:
    string trimTrailingVowels(string s) {
        int k=0;
        vector<char>v={'a', 'e', 'i', 'o', 'u'};
        int j=s.size()-1;
        while(j>=0&&find(v.begin(),v.end(),s[j])!=s.end())
        {
            j--;
        }
        s.erase(j+1,s.size()-j-1)
        return s;
    }
};
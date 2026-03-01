class Solution {
private:
    bool isVowel(char c)
    {
        return c=='a'|| c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        int i=n-1;
        while(i>=0&&isVowel(s[i]))
        {
            i--;
        }
        s.resize(i+1);
        return s;
    }
};
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;
class Solution {
private:
    string get_key(string s)
    {
        int diff = s[0] - 'a'; 
        for (int i = 0; i < s.size(); i++)
        {
            int val = s[i] - diff;           
            if (val < 'a') {
                val += 26;
            }
            s[i] = val; 
        }
        return s; 
    }

public:
    long long countPairs(vector<string>& words) 
    {
        long long n = 0;
        unordered_map<string, int> map; 
        for (const string& word : words)
        {
            string key = get_key(word);           
            n += map[key]; 
            map[key]++;
        }
        return n;    
    }
};
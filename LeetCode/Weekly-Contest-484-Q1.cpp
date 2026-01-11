#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
class Solution {
        int  different(const string &s,int len)
        {
            vector<char>v;
            for (int i=0;i<len;i++)
            {
                if (find(v.begin(), v.end(), s[i]) == v.end())
                {
                    v.push_back(s[i]);
                }
            }
            return v.size();
        }

public:
    int residuePrefixes(string s) 
    {
        int len =1;
        int n=0;
        while (len<=s.size())
        {
            if (different(s,len)==len%3)
            {
                n++;
            }
            len++;
        }
        return n;   
    }
};
int main() {
    Solution sol;
    string input1;
    cout << "请输入一个字符串测试 (例如 abacaba): ";
    cin >> input1;
    int result = sol.residuePrefixes(input1);
    cout << "计算结果: " << result << endl;
    return 0;
}
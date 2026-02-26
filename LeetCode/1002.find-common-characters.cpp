/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        int arr1[26]={0};//统计各字符串单个字符的最少个数
        for(char c:words[0])
        {
            arr1[c-'a']++;
        }
        for(int i=1;i<n;i++)
        {
            const string& s = words[i];
            int arr2[26]={0};
            for(char c:s)
            {
                arr2[c-'a']++;
            }
            for(int j=0;j<26;j++)
            {
                if(arr2[j]<arr1[j]) arr1[j]=arr2[j];
            }
        }
        vector<string>result;
        for(int i=0;i<26;i++)
        {
            while(arr1[i]>0)
            {
                result.push_back(string(1,i+'a'));
                arr1[i]--;
            }
        }
        return result;
        
    }
};
// @lc code=end


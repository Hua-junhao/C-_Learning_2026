/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int arr1[26]={0};
        int arr2[26]={0};
        int count=0;
        for(int i=0;i<n;++i)
        {
            char c=word[i];
            if('a'<=c && c<='z')
            {
                arr1[c-'a']=i+1;
            }
            else
            {
                if(arr2[c-'A']==0) arr2[c-'A']=i+1;
            }
        }
        for(int i=0;i<26;++i)
        {
            if(arr1[i]!=0 && arr2[i]!=0 && arr2[i]>arr1[i])
            {
                count++;
            }
        }
        return count;

        
    }
};
// @lc code=end


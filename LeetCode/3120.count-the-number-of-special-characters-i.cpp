/*
 * @lc app=leetcode id=3120 lang=cpp
 *
 * [3120] Count the Number of Special Characters I
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int arr1[26]={0};
        int arr2[26]={0};
        int n=word.size();
        int count=0;
        for(int i=0;i<n;++i)
        {
            char c=word[i];
            if('a'<=c && c<='z') 
            {
                arr1[c-'a']=1;
            }
            else
            {
                arr2[c-'A']=1;
            }
        }
        for(int i=0;i<26;++i)
        {
            if(arr1[i]==1 && arr2[i]==1) count++;
        }
        return count;
        
    }
};
// @lc code=end


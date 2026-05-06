/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>result;
        int arr[27]={0};
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            arr[s[i]-'a']=i;
        }
        int left=0;
        int right=0;
        for(int i=0;i<n;++i)
        {
            right=max(right,arr[s[i]-'a']);
            if(i==right)
            {
                result.push_back(right-left+1);
                left=right+1;
            }
        }
        return result;
        
    }
};
// @lc code=end


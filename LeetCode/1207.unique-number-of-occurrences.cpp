/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                map[arr[i]]++;
                l++;
            }
            else if(arr[i]==arr[i-1])
            {
                map[arr[i]]++;
            }
            else
            {
                arr[l]=arr[i];
                l++;
                map[arr[i]]++;
            }
        }
        vector<int>v;
        for(int i=0;i<l;i++)
        {
            if(i==0)
            {
                v.push_back(map[arr[i]]);
            }
            else if(find(v.begin(),v.end(),map[arr[i]])!=v.end())
            {
                return false;
            }
            else 
            {
                v.push_back(map[arr[i]]);
            }
        }
        return true;
        
    }
};
// @lc code=end


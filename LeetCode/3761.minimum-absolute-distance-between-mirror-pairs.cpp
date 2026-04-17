/*
 * @lc app=leetcode id=3761 lang=cpp
 *
 * [3761] Minimum Absolute Distance Between Mirror Pairs
 */

// @lc code=start
class Solution {
public:
    int Mirror(int i)
    {
        string s=to_string(i);
        int k=0;
        for(int j=s.size()-1;j>=0;j--)
        {
            if(j==s.size()&&s[j]=='0') continue;
            k=k*10+s[j]-'0';
        }
        return k;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        vector<int>nums2;
        nums2.resize(nums.size());
        int result=-1;
        for(int i=0;i<nums.size()-1;++i)
        {
            nums2[i]=Mirror(nums[i]);
        }
        for(int i=0;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[j]==nums2[i])
                {
                    if(result==-1||j-i<result) result=j-i;
                }
            }
        }
        return result;
        
    }
};
// @lc code=end


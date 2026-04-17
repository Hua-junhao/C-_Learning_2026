/*
 * @lc app=leetcode id=3761 lang=cpp
 *
 * [3761] Minimum Absolute Distance Between Mirror Pairs
 */

// @lc code=start
class Solution {
public:
    int Mirror(int num)
    {
        int rev=0;
        while(num>0)
        {
            rev=rev*10+num%10;
            num=num/10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>map;
        int mindis=-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int target = Mirror(nums[i]);
            if(map.count(target)>0)
            {
                if(mindis==-1||map[target]-i<mindis) mindis=map[target]-i;
            }
            map[nums[i]]=i;
        }
        return mindis;
        
    }
};
// @lc code=end


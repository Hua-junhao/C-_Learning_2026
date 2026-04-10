class Solution {
public:
    void backtracking(vector<int>&nums,vector<vector<int>>&result,int first)
    {
        if(first==nums.size())
        {
            result.push_back(nums);
            return;
        }
        int used[21]={0};
        for(int i=first;i<nums.size();++i)
        {
           if(used[nums[i]+10]) continue;
           used[nums[i]+10]=1;
           swap(nums[first],nums[i]);
           backtracking(nums,result,first+1);
           swap(nums[first],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        backtracking(nums,result,0);
        return result;

    }
};
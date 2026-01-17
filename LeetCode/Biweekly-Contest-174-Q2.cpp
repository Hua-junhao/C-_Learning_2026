class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        unordered_set<int> v;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target[i])
            {
                continue;
            }
            else
            {
                    v.insert(nums[i]);
            }
        }
        return v.size();    
    }
};
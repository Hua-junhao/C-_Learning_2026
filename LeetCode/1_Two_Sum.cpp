//1.双重循环暴力枚举(Brute Force)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i=0;i<nums.size();i++)
//     {
//         for (int j=i+1;j<nums.size();j++)
//         {
//             if(nums[i]+nums[j]==target) return{i,j};
//         }
//     }return{};    
//     }
// };
//2.哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            
            int complement = target - nums[i];
            if (hashTable.find(complement) != hashTable.end()) 
            {
                return {hashTable[complement], i};
            }
            hashTable[nums[i]] = i;
        }
        
        return {};
    }
};
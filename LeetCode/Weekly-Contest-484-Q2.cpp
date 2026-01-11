#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution {
private:
    int to_sum(const vector <int>&nums,int i)
    {
        long long sum=0;
        int n=0;
        vector <int> v;
        while(i<nums.size())
        {
            sum+=nums[i];
            v.push_back(nums[i]);
            if(find(v.begin(), v.end(),sum) != v.end()) n++;
            i++;
        }
        return n;
    }
public:
    int centeredSubarrays(vector<int>& nums) {
    int n=0;
    for (int i=0;i<nums.size();i++)
    {
        n+=to_sum(nums,i); 
    }
      return n;        
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5}; 
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    int result = sol.centeredSubarrays(nums);
    cout << "Output: " << result << endl;
    return 0;
}
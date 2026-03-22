class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>v;
        int min=nums1[0];
        for(int i:nums1)
        {
            if(i%2==1) v.push_back(i);
            if(i<min) min=i;
        }
        int n=v.size();
        if(n==0||n==nums1.size()||min%2==1) return true;
        return false;
        
    }
};©leetcode
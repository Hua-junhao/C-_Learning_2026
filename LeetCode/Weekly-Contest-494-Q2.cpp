class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcout=0;
        int min=nums1[0];
        for(int i:nums1)
        {
            if(i%2==1) oddcout++;
            if(i<min) min=i;
        }
        return (oddcout==0||oddcout==nums1.size()||min%2==1);      
    }
};©leetcode
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int MOD = 1e9 + 7;
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        map2[0] = 1; 
        int current = 0;
        int result = 0; 
        for (int num : nums) {
            current^= num;             
            int ways1 = 0;
            if (map2.count(current ^ target1)) {
                ways1 = map2[current ^ target1];
            }
            int ways2 = 0;
            if (map1.count(current ^ target2)) {
                ways2 = map1[current ^ target2];
            }
            if (ways1 > 0) {
                map1[current] = (map1[current] + ways1) % MOD;
            }
            if (ways2 > 0) {
                map2[current] = (map2[current] + ways2) % MOD;
            }
            result = (ways1 + ways2) % MOD;
        }
        return result;
    }
};
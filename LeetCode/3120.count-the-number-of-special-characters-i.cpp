class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower_mask = 0;
        int upper_mask = 0; 
        for (char c : word) {
            if (islower(c)) {
                lower_mask |= (1 << (c - 'a')); 
            } else {
                upper_mask |= (1 << (c - 'A'));
            }
        }
        int special_mask = lower_mask & upper_mask;
        return __builtin_popcount(special_mask);
    }
};
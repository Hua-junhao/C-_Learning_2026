class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>character;
        int maxlength=1;
        if (s.empty()) return 0;
        if (s.size()==1) return 1;
        int left=0;
        character[s[left]]=left;
        for (int right=1;right<s.size();right++)
        {
            if (character.count(s[right]))//判断是否出现过
            {
                left=max(character[s[right]]+1,left);
            }
            character[s[right]]=right;
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
    }
};
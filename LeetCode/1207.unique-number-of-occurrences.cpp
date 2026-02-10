/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        unordered_set<int>set;
        for(int i:arr)
        {
            map[i]++;
        }
        for(auto& pair:map)
        {
            set.insert(pair.second);
        }
        return set.size()==map.size();
        
    }
};
// @lc code=end


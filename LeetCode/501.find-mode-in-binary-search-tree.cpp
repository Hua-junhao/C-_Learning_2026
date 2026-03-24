/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode*root,unordered_map<int,int>&map,int &max)
    {
        if(!root) return;
        map[root->val]++;
        if(map[root->val]>max) max=map[root->val];
        traversal(root->left,map,max);
        traversal(root->right,map,max);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>map;
        int max=0;
        traversal(root,map,max);
        vector<int>v;
        for(auto it=map.begin();it!=map.end();++it)
        {
            if(it->second==max) v.push_back(it->first);
        }
        return v;
        
    }
};
// @lc code=end


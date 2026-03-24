/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int mindiff=INT_MAX;
    void validate(TreeNode* node, TreeNode*& prev) {
        if (!node) return; 
        validate(node->left, prev);
        if(prev != nullptr) mindiff=min(abs(prev->val-node->val),mindiff);
        prev = node;
        validate(node->right, prev);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=nullptr;
        validate(root,prev);
        return mindiff;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool validate(TreeNode* node, TreeNode*& prev) {
        if (!node) return true; 
        // 左
        if (!validate(node->left, prev)) return false;
        // 中
        if (prev != nullptr && prev->val >= node->val) {
            return false;
        }
        prev = node;
        // 右
        return validate(node->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return validate(root,prev);
    }
};
// @lc code=end


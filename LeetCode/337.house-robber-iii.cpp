/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return root->val;
        int val1=0;
        if(root->right!=nullptr) val1+=rob(root->right->left)+rob(root->right->right);
        if(root->left!=nullptr) val1+=rob(root->left->left)+rob(root->left->right);
        return max(root->val+val1,rob(root->left)+rob(root->right));    
    }
};
// @lc code=end


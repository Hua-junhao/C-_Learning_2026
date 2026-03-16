/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        int l=0,r=0;
        while(left)
        {
            l++;
            left=left->left;
        }
        while(right)
        {
            r++;
            right=right->right;
        }
        if(l==r) return (1<<l+1)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
// @lc code=end


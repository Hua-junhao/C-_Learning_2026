/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    void traversal(TreeNode* root,int &pre)
    {
        if(!root) return;
        traversal(root->right,pre);
        pre+=root->val;
        root->val=pre;
        traversal(root->left,pre);
    }
    TreeNode* convertBST(TreeNode* root) {
        int pre=0;
        traversal(root,pre);
        return root;
        
    }
};
// @lc code=end


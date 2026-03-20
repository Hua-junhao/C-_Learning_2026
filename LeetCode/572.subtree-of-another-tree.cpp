/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool compare(TreeNode*root,TreeNode*subRoot)
    {
        if(root==nullptr&&subRoot==nullptr) return true;
        if(root==nullptr||subRoot==nullptr||root->val!=subRoot->val) return false;
        return compare(root->left,subRoot->left)&&compare(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;
        return compare(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot); 
    }
};
// @lc code=end


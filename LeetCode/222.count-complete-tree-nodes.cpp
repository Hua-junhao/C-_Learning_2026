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
    void coutlen(int &n,TreeNode*cur)
    {
        if(cur==nullptr) return;
        if(cur->left) n++;
        if(cur->right) n++;
        coutlen(n,cur->left);
        coutlen(n,cur->right);
    }
    int countNodes(TreeNode* root) {
        int n=1;
        if(root==nullptr) return 0;
        coutlen(n,root);
        return n;
    }
};
// @lc code=end


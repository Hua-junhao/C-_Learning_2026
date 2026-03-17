/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int depth(TreeNode*cur)
    {
        if(cur==nullptr) return 0;
        int leftheight=depth(cur->left);
        if(leftheight==-1) return -1;
        int rightheight=depth(cur->right);
        if(rightheight==-1) return -1;
        if(abs(leftheight-rightheight)>1) return -1;
        return 1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) {
            return depth(root)!=-1;
    }
};
// @lc code=end


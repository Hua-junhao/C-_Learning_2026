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
    array<int,2> robtree(TreeNode*cur){
        if(cur==nullptr) return {0,0};
        array<int,2>left=robtree(cur->left);
        array<int,2>right=robtree(cur->right);
        int val0=max(left[0],left[1])+max(right[0],right[1]);
        int val1=cur->val+left[0]+right[0];
        return {val0,val1};
    }
    int rob(TreeNode* root) {
        array<int,2>result=robtree(root);
        return max(result[0],result[1]);
    }
};
// @lc code=end


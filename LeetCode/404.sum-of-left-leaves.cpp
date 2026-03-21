/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sum_left(TreeNode*cur,bool isleft)
    {
        if(!cur) return 0;
        if(!cur->left&&!cur->right&&isleft) return cur->val;
        return sum_left(cur->left,true)+sum_left(cur->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int result=sum_left(root,false);
        return result;
    }
};
// @lc code=end


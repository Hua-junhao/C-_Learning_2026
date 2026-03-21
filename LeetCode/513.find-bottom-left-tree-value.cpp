/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int maxdepth=-1;
    int result=0;
    void dfs(TreeNode* cur,int depth)
    {
        if(!cur) return;
        if(depth>maxdepth)
        {
            maxdepth=depth;
            result=cur->val;
        }
        dfs(cur->left,depth+1);
        dfs(cur->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return result;
    }
};
// @lc code=end


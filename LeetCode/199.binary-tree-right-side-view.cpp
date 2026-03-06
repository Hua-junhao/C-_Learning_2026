/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void dfs(TreeNode*cur,int depth,vector<int>&res)
    {
        if(cur==nullptr) return;
        if(res.size()==depth)
        {
            res.push_back(cur->val);
        }
        dfs(cur->right,depth+1,res);
        dfs(cur->left,depth+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        dfs(root,0,res);
        return res;
        
    }
};
// @lc code=end


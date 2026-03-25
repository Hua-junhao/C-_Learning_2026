/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* result=root;
        if(!root)
        {
            TreeNode* cur=new TreeNode(val);
            return cur;
        }
        while(root)
        {
            if(root->val>val)
            {
                if(!root->left) 
                {
                    TreeNode* cur=new TreeNode(val);
                    root->left=cur;
                    break;
                }
                else
                {
                    root=root->left;
                    continue;
                }
                
            }
            else
            {
                if(!root->right)
                {
                    TreeNode* cur=new TreeNode(val);
                    root->right=cur;
                    break;
                }
                else
                {
                    root=root->right;
                    continue;
                }
            }
        }
        return result;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key)
        {
            if(!root->left&&!root->right)
            {
                delete root;
                return nullptr;
            }
            if(!root->left)
            {
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            }
            if(!root->right)
            {
                TreeNode* tmp=root->left;
                delete root;
                return tmp;
            }
            else
            {
                TreeNode* cur=root->right;
                while(cur->left!=nullptr)
                {
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            }

        }
        if(root->val>key) root->left=deleteNode(root->left,key);
        if(root->val<key) root->right=deleteNode(root->right,key);
        return root;
    }
};
// @lc code=end


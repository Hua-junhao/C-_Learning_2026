/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* cur=root;
        vector<int>result;
        while(cur!=nullptr||!st.empty())
        {
            if(cur!=nullptr)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                st.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>result;
        if(root==nullptr) return result;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left!=nullptr) st.push(node->left);
            if(node->right!=nullptr) st.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end


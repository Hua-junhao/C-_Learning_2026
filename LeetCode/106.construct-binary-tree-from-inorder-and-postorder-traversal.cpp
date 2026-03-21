/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    unordered_map<int, int> map; 
    TreeNode* traversal(vector<int>& inorder, int inBegin, int inEnd, vector<int>& postorder, int postBegin, int postEnd)
    {
        if (postBegin >= postEnd) return nullptr;
        int rootVal = postorder[postEnd - 1];
        TreeNode* root = new TreeNode(rootVal);
        int delimiterIndex = map[rootVal];
        root->left = traversal(inorder, inBegin, delimiterIndex, postorder, postBegin, postBegin + (delimiterIndex - inBegin));
        root->right = traversal(inorder, delimiterIndex + 1, inEnd, postorder, postBegin + (delimiterIndex - inBegin), postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map.clear();
        for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());  
    }
};
// @lc code=end


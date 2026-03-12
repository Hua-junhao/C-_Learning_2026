/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*>que;
        int mindepth=0;
        if(root==nullptr) return mindepth;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            mindepth++;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=que.front();
                que.pop();
                if(cur->left==nullptr&&cur->right==nullptr) return mindepth;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return mindepth;
        
    }
};
// @lc code=end


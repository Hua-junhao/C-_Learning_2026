/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>finalresult;
        stack<vector<int>>result;
        queue<TreeNode*>que;
        if(root==nullptr) return finalresult;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            vector<int>v;
            v.reserve(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=que.front();
                que.pop();
                v.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push(v);
        }
        while(!result.empty())
        {
            finalresult.push_back(result.top());
            result.pop();
        }
        return finalresult;

        
    }
};
// @lc code=end


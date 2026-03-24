/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    void traversal(TreeNode*root,TreeNode*&pre,vector<int>&v,int&count,int &max)
    {
        if(!root) return;
        traversal(root->left,pre,v,count,max);
        if(pre==nullptr) count=1;
        else if(pre->val==root->val) count++;
        else count=1;
        pre=root;
        if(count==max) v.push_back(root->val);
        else if(count>max)
        {
            v.clear();
            max=count;
            v.push_back(root->val);
        }
        traversal(root->right,pre,v,count,max);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        int max=0;
        int count=0;
        TreeNode* pre=nullptr;
        traversal(root,pre,v,count,max);
        return v;
        
    }
};
// @lc code=end


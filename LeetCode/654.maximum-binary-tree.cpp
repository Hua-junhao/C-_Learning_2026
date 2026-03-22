/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*>stk;
        for(int i:nums)
        {
            TreeNode* cur=new TreeNode(i);
            while(!stk.empty()&&stk.back()->val<i)
            {
                cur->left=stk.back();
                stk.pop_back();
            }
            if(!stk.empty())
            {
                stk.back()->right=cur;
            }
            stk.push_back(cur);
        }  
        return stk.front();
    }
};
// @lc code=end


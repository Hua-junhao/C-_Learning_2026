/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void findpath(TreeNode*cur,int targetSum,vector<int>&v,vector<vector<int>>&result)
    {
        if(!cur) return;
        v.push_back(cur->val);
        targetSum-=cur->val;
        if(!cur->left && !cur->right)
        {
            if(targetSum==0) result.push_back(v);
        }
        else
        {
            if(cur->left) findpath(cur->left,targetSum,v,result);
            if(cur->right) findpath(cur->right,targetSum,v,result);
        }
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>v;
        findpath(root,targetSum,v,result);
        return result;
        
    }
};
// @lc code=end


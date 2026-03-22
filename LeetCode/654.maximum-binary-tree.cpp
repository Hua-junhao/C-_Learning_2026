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
    TreeNode* traversal(vector<int>&nums,int begin,int end)
    {
        if(begin>=end) return nullptr;
        int maxindex=begin;
        for(int i=begin+1;i<end;++i)
        {
            if(nums[i]>nums[maxindex]) maxindex=i;
        }
        TreeNode* cur=new TreeNode(nums[maxindex]);
        cur->left=traversal(nums,begin,maxindex);
        cur->right=traversal(nums,maxindex+1,end);
        return cur;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=traversal(nums,0,nums.size());
        return root;    
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>result;
        queue<TreeNode*>que;
        if(root==nullptr) return result;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            double sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=que.front();
                que.pop();
                sum+=cur->val;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            double average=sum/size;
            result.push_back(average);
        }
        return result;

    }
};
// @lc code=end


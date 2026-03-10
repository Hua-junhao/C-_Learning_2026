/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        queue<TreeNode*>que;
        if(root==nullptr) return result;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            int max_val=INT_MIN;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=que.front();
                que.pop();
                max_val=max(max_val,cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(max_val);
        }
        return result;
        
    }
};
// @lc code=end


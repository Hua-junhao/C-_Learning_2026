/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool traveral(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr&&q==nullptr)
        {
            return true;
        }
        else if(p==nullptr||q==nullptr||p->val!=q->val)
        {
            return false;
        }
        else
        {
            return traveral(p->left,q->left)&&traveral(p->right,q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traveral(p,q);
    }
};
// @lc code=end


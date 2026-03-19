/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void traveral(TreeNode* cur,vector<int>&path,vector<string>&result)
    {
        path.push_back(cur->val);
        if(cur->left==nullptr&&cur->right==nullptr)
        {
            string s;
            for(int i=0;i<path.size()-1;i++)
            {
                s+=to_string(path[i]);
                s+="->";
            }
            s+=to_string(cur->val);
            result.push_back(s);
            return;
        }
        if(cur->left)
        {
            traveral(cur->left,path,result);
            path.pop_back();
        }
        if(cur->right)
        {
            traveral(cur->right,path,result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        vector<int>path;
        if(root==nullptr) return result;
        traveral(root,path,result);
        return result;
    }
};
// @lc code=end


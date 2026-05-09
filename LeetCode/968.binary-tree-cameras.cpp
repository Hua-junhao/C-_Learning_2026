/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    int traversal(TreeNode* cur,int &result)
    {
        if(cur==nullptr) return 2;//2 为有覆盖
        int left=traversal(cur->left,result);
        int right=traversal(cur->right,result);    
        if(left==0||right==0)//0 为无覆盖
        {
            result++;
            return 1;//1 为有摄像头
        }
        else if(left==1||right==1)
        {
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int result=0;
        if(traversal(root,result)==0)//root 无覆盖
        {
            result++;
        }
        return result;
        
    }
};
// @lc code=end


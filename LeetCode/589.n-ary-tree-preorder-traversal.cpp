/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversal(Node*root,vector<int>&result)
    {
        if(root==nullptr) return;
        result.push_back(root->val);
        for(Node*cur:root->children)
        {
            traversal(cur,result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>result;
        traversal(root,result);
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
        for(Node*cur:root->children)
        {
            traversal(cur,result);
        }
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>result;
        traversal(root,result);
        return result;
    }
};
// @lc code=end


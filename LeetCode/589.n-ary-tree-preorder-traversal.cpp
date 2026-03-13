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
    vector<int>result;
    void traversal(Node*root)
    {
        if(root==nullptr) return;
        result.push_back(root->val);
        for(Node*cur:root->children)
        {
            traversal(cur);
        }
    }
    vector<int> preorder(Node* root) {
        traversal(root);
        return result;
    }
};
// @lc code=end


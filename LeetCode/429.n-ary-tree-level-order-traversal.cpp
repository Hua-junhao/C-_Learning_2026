/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(Node*root) {
        vector<vector<int>>result;
        if(root==nullptr) return result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v;
            int n=q.size();
            v.reserve(n);
            for(int i=0;i<n;i++)
            {
                Node*cur=q.front();
                q.pop();
                v.push_back(cur->val);
                for(Node*curr:cur->children)
                {
                    q.push(curr);
                }
            }
            result.push_back(v);
        }
        return result;
    }
};
// @lc code=end


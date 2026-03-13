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
    vector<int> postorder(Node* root) {
        vector<int>result;
        stack<Node*>sta;
        if(root==nullptr) return result;
        sta.push(root);
        while(!sta.empty())
        {
            Node*cur=sta.top();
            sta.pop();
            result.push_back(cur->val);
            for(Node* ccur:cur->children)
            {
                if(ccur!=nullptr)
                {
                    sta.push(ccur);
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end


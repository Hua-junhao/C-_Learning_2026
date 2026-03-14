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
    vector<int> preorder(Node* root) {
        vector<int>result;
        stack<Node*>sta;
        if(root==nullptr) return result;
        sta.push(root);
        while(!sta.empty())
        {
            Node*cur=sta.top();
            sta.pop();
            result.push_back(cur->val);
            for(auto it=cur->children.rbegin();it!=cur->children.rend();++it)
            {
                if(*it!=nullptr) st.push(*it);
            }
        }
        return result;
    }
};
// @lc code=end


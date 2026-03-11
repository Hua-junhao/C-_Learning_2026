class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>que;
        if(root==nullptr) return nullptr;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                Node* cur=que.front();
                que.pop();
                if(i<size-1) 
                {
                    cur->next=que.front();
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
        
    }
};
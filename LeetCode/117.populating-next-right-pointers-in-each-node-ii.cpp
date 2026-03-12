class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        Node* cur=root;
        while(cur!=nullptr)
        {
            Node dummy(0);
            Node* tail=&dummy;
            while(cur!=nullptr)
            {
                if(cur->left!=nullptr)
                {
                    tail->next=cur->left;
                    tail=tail->next;
                }
                if(cur->right!=nullptr)
                {
                    tail->next=cur->right;
                    tail=tail->next;
                }
                cur=cur->next;
            }
            cur=dummy->next;
        }
        return root;
        
    }
};
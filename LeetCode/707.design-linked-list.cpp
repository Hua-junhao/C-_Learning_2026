/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}

    };
    ListNode*dummyhead;
    int size;

public:
    MyLinkedList() {
        dummyhead=new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        if(index>=size||index<0){
            return -1;
        }
        ListNode* cur=dummyhead->next;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index<0) index=0;
        ListNode *New=new ListNode(val);
        ListNode*pre=dummyhead;
        while(index--)
        {
            pre=pre->next;
        }
        New->next=pre->next;
        pre->next=New;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=  size||index<0) return;
        ListNode*pre=dummyhead;
        while(index--){
            pre=pre->next;
        }
        ListNode*del =pre->next;
        pre->next=del->next;
        delete del;
        del=nullptr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end


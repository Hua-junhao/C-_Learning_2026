/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int size=0;
        while(cur!=nullptr)
        {
            size++;
            cur=cur->next;
        }
        int k=size-n;
        ListNode*dummyhead=new ListNode(0);
        dummyhead->next=head;
        ListNode* pre=dummyhead;
        cur=head;
        while(k--)
        {
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        ListNode*result=dummyhead->next;
        delete dummyhead;
        return result;
    }
};
// @lc code=end


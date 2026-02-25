/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* pre=nullptr;
        ListNode* cur=slow->next;
        slow->next=nullptr;
        while (cur!=nullptr)
        {
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        ListNode* l=head;
        ListNode* r=pre;
        while(l!=nullptr&&r!=nullptr)
        {
            ListNode* tmp1=l->next;
            ListNode* tmp2=r->next;
            l->next=r;
            r->next=tmp1;
            l=tmp1;
            r=tmp2;
        }
        return;
    }
};
// @lc code=end


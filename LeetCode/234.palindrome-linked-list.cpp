/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            ListNode*tmp =cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondhead=reverseList(slow);
        ListNode* tmp1=head;
        ListNode* tmp2=secondhead;
        while(tmp1!=nullptr&&tmp2!=nullptr)
        {
            if(tmp1->val!=tmp2->val) return false;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        reverseList(secondhead);
        return true;
    }
};
// @lc code=end


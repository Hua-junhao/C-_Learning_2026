/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                ListNode*tmp1=fast;
                ListNode*tmp2=head;
                while (tmp1!=tmp2)
                {
                    tmp1=tmp1->next;
                    tmp2=tmp2->next;
                }
                return tmp1;
            }
        }
        return nullptr;
        
    }
};
// @lc code=end


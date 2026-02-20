 /*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre=head;
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode* cur=head->next;
        ListNode* tmp=pre;
        ListNode* result=cur;
        while (cur!=nullptr)
        {
            if(pre!=head)
            {  
                tmp->next=cur;
            }
            pre->next=cur->next;
            cur->next=pre;
            tmp=pre;
            pre=pre->next;
            if(pre==nullptr) break;
            cur=pre->next;
        }
        return result;
    }
};
// @lc code=end


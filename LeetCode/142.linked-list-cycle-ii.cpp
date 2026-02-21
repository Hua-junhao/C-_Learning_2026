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
        unordered_set<ListNode*>s;
        while(head!=nullptr)
        {
            if(s.find(head)==s.end())
            {
                s.insert(head);
            }
            else
            {
                return head;
            }
            head=head->next;
        }
        return nullptr;

        
    }
};
// @lc code=end


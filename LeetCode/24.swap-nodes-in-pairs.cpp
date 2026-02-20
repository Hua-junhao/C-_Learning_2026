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
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        ListNode* cur=dummyhead;
        while(cur->next!=nullptr&&cur->next->next!=nullptr)
        {
            ListNode* tmp1=cur->next;
            ListNode* tmp2=tmp1->next;
            tmp1->next=tmp2->next;
            tmp2->next=tmp1;
            cur->next=tmp2;
            cur=tmp1;
        }
        ListNode*result=dummyhead->next;
        delete dummyhead;
        return result;
    }
};
// @lc code=end


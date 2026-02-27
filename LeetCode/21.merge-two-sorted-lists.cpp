/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pre=nullptr;
        ListNode* head;
        if(list1==nullptr&&list2==nullptr) return nullptr;
        else if(list1==nullptr||(list2!=nullptr&&list2->val<list1->val))
        {
            head=list2;
            pre=list2;
            list2=list2->next;
        }
        else
        {
            head=list1;
            pre=list1;
            list1=list1->next;
        }
        while(list1!=nullptr||list2!=nullptr)
        {
            if(list1==nullptr||(list2!=nullptr&&list2->val<list1->val))
            {
                pre->next=list2;
                pre=list2;
                list2=list2->next;
            }
            else
            {
                pre->next=list1;
                pre=list1;
                list1=list1->next;
            }
        }
        return head;
    }
};
// @lc code=end


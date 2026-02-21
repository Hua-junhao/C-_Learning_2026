/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1=headA;
        ListNode* tmp2=headB;
        int size1=0,size2=0;
        while (tmp1!=nullptr)
        {
            size1++;
            tmp1=tmp1->next;
        }
        while (tmp2!=nullptr)
        {
            size2++;
            tmp2=tmp2->next;
        }
        tmp1=headA;
        tmp2=headB;
        if(size1<size2)
        {
            swap(size1,size2);
            swap(tmp1,tmp2);
        }
        int diff=size1-size2;
        while (diff--)
        {
            tmp1=tmp1->next;
        }
        while (tmp1!=nullptr)
        {
            if(tmp1==tmp2)
            {
                return tmp1;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return nullptr;
    }
};
// @lc code=end


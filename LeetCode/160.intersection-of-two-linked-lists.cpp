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
        while(tmp1!=nullptr)
        {
            ListNode* tmp2=headB;
            while(tmp2!=nullptr)
            {
                if(tmp1==tmp2)
                {
                    return tmp1;
                }
                tmp2=tmp2->next;
            }
            tmp1=tmp1->next;
        }
        return nullptr;
        
    }
};
// @lc code=end


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
        vector<ListNode*>vec;
        ListNode* cur=head;
        if(cur==nullptr||cur->next==nullptr) return;
        while(cur!=nullptr)
        {
            vec.push_back(cur);
            cur=cur->next;
        }
        bool flag=1;
        cur=head;
        int i=1,j=vec.size()-1;
        while(i<=j)
        {
            if(flag)
            {
                flag=0;
                cur->next=vec[j];
                cur=vec[j];
                j--;
            }
            else
            {
                flag=1;
                cur->next=vec[i];
                cur=vec[i];
                i++;
            }
        }
        cur->next=nullptr;
        return;
    }
};
// @lc code=end


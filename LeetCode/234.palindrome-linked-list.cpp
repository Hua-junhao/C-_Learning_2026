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
    bool isPalindrome(ListNode* head) {
        vector<int>vec;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            vec.push_back(cur->val);
            cur=cur->next;
        }
        int i=0,j=vec.size()-1;
        while(i<j)
        {
            if(vec[i]!=vec[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
};
// @lc code=end


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
        if(!head || !head->next)
            return true;
        ListNode *fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *mid=slow->next;
        mid = reverseList(mid);
        while(mid)
        {
            if(mid->val != head->val)
                return false;
            mid = mid->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        // ListNode *curr = head;
        ListNode* next = NULL;
        while(head)
        {
            next = head->next;
            head->next=pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
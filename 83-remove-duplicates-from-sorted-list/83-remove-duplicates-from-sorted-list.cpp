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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* del = head;
        while(curr){
            while(curr->next &&curr->val == curr->next->val){
                del = curr->next;
                curr->next = curr->next->next;
                delete del; 
            }
             curr = curr->next;
        }
        return head;
    }
};
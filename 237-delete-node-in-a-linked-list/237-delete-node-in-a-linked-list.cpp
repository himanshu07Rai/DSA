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
    void deleteNode(ListNode* node) {
        int temp = node->next->val;
        node->val = temp;
        ListNode *t = node->next; 
        node->next = node->next->next;
        delete(t);
    }
};
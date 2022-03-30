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
        if(!head || !head->next)
            return head;
        ListNode *p = head,*a = head;
        head = head->next;
        while(head)
        {
            cout<<p->val<<" "<<head->val<<"\n";
            if(head->val==p->val)
            {
                p->next=head->next;
            }
            else{
                p = p->next;
            }            
            head = head->next;
        }
        return a;
    }
};
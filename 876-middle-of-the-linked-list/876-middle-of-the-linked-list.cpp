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
    ListNode* middleNode(ListNode* head) {
        // if(!head || !head->next)
        //     return head;
        // ListNode *t=head;
        // int count=0;
        // while(t)
        // {
        //     count++;
        //     t=t->next;
        // }
        // ListNode *s=head, *f=head->next;
        // while(f)
        // {
        //     f=f->next;
        //     if(f)
        //     {
        //         s=s->next;
        //         f=f->next;
        //     }
        // }
        // if(count&1)
        //     return s;   
        // return s->next;
        
        ListNode* fast = head;
        ListNode* slow = fast;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow=slow->next;
        }

        return slow;    
    }
};
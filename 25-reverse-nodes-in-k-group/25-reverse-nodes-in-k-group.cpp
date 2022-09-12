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
    void reverse(ListNode *s,ListNode *e){
        ListNode *c = s,*p=NULL,*n = s->next;
        while(p!=e){
            c->next = p;
            p=c;
            c=n;
            if(n)
                n=n->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head ||  !head->next || k==1)return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *beforeStart = dummy,*e = head;
        int i=0;
        while(e)
        {
            i++;
            if(i%k==0)
            {
                ListNode *s = beforeStart->next,*afterEnd = e->next;
                reverse(s,e);
                beforeStart->next = e;
                s->next = afterEnd;
                beforeStart = s;
                e = afterEnd;
            }else{
                e=e->next;
            }
        }
        
        return dummy->next;
    }
};
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
        ListNode *s = head,*e = head;
        int t = k-1;
        while(t--){
            e = e->next;
            if(!e)return head;
        }
        ListNode *nextHead = reverseKGroup(e->next,k);
        reverse(s,e);
        s->next = nextHead;
        return e;
    }
};
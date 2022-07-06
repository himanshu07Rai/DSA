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
    ListNode* divide(ListNode* head)
    {
        auto s = head,f=head,prev=head;
        while(f && f->next)
        {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        if(f)
        {
            prev = s->next;
            s->next = NULL;
            return prev;
        }
        prev->next = NULL;
        return s;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        auto p = head, c = head->next,n = head->next->next;
        p->next=NULL;
        while(n)
        {
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        return c;        
    }
    void reorderList(ListNode* head) {
        // if(!head || !head->next || !head->next->next)
        //     return head;
        auto f = head;
        auto s = divide(head);
        // cout<<s->val;
        // return s;
        s = reverse(s);
        while(f && s)
        {
            auto s2 = s->next;
            s->next = f->next;
            f->next = s;
            f = f->next->next;
            s = s2;
        }
    }
};
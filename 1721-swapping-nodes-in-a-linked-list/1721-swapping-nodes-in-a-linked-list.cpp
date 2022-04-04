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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode *t = head;
        int n=0;
        while(t)
        {
            n++;
            t=t->next;
        }
        // cout<<n<<"\n";
        ListNode* temp = head,*f=NULL,*s=NULL;
        while(temp)
        {
            count++;
            if(count==k)
            {
                f = temp;
            }
            if(count==n-k+1)
            {
                s=temp;
            }
            // cout<<f->val<<" "<<s->val;
            if(f&&s)
                break;
            temp=temp->next;
        }
        swap(f->val,s->val);
        return head;
    }
};
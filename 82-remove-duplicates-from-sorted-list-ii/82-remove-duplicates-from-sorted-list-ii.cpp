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
        ListNode*curr = head;
        ListNode*del = head;
        unordered_map<int,int> m;
        while(curr)
        {
            m[curr->val]++; 
            curr = curr->next;                           
        }
        curr = head;
        ListNode *ans = new ListNode(0);
        ListNode *t = ans;
        while(curr)
        {
            if(m[curr->val]==1)
            {
                ListNode *temp = new ListNode(curr->val);
                t->next = temp;
                t = t->next;
            }
            curr=curr->next;
        }
        return ans->next;
    }
};
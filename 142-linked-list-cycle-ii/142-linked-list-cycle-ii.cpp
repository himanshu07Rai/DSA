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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(!fast || !fast->next)
            return NULL;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                break;
            }
        }
        if(slow!=fast)
        return NULL;
        slow = head;
        if(fast==slow)
        {
            while(fast->next!=slow)
                fast = fast->next;
        }
        else{
            while(fast->next!=slow->next)
            {
                slow=slow->next;
                fast = fast->next;
            }
        }
        return fast->next;
    }
};
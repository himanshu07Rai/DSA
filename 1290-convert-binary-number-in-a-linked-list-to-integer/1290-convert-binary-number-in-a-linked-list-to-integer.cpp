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
    int getDecimalValue(ListNode* head) {
        // int ans = 0;
        // while(head)
        // {
        //     ans*=2;
        //     ans+=head->val;
        //     head=head->next;
        // }
        // return ans;
        ListNode* temp = head;
    	int n = 0;
    	while(temp != NULL) {
    		n++;
    		temp = temp->next;
    	}

    	temp = head;
    	int ans = 0;
    	while(temp != NULL) {
    		ans += (temp->val) * pow(2, --n);
            temp = temp->next;
    	}

    	return ans;
    }
};
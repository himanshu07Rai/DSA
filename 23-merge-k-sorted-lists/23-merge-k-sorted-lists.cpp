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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        // return lists[0];
        ListNode* dummy = new ListNode();
        ListNode* tail=dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(int i=0;i<n;i++)
        {
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        vector<int>re;
        
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            tail->next = t.second;
            tail = tail->next;
            
            if(t.second->next)
                pq.push({t.second->next->val,t.second->next});
                
        }
        return dummy->next;
    }
};
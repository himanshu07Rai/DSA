/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Node{
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
}
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node* ans = new Node(0);
        auto t = ans;
        while(head)
        {
            Node* temp;
            if(m.find(head)==m.end())
            {
                temp = new Node(head->val);
                m[head] = temp;
            }
            else
                temp = m[head];
            if(head->next==NULL)
                temp->next=NULL;
            else if(m.find(head->next)==m.end())
            {
                Node* nex = new Node(head->next->val);
                temp->next = nex;
                m[head->next] = nex;
            }else{
                temp->next = m[head->next];
            }
            
            if(head->random==NULL)
                temp->random=NULL;
            else if(m.find(head->random)==m.end())
            {
                Node* ran = new Node(head->random->val);
                temp->random = ran;
                m[head->random] = ran;
            }else{
                temp->random = m[head->random];
            }
            
            head=head->next;
            t->next = temp;
            t = temp;
            
        }
        return ans->next;
    }
};
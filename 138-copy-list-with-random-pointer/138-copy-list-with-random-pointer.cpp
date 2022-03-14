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
        // unordered_map<Node*,Node*>m;
        // Node* ans = new Node(0);
        // auto t = ans;
        Node* temp = head;
        while(temp)
        {
            Node *copy = new Node(temp->val); 
            copy->next = temp->next;
            temp->next = copy;  
            temp = copy->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->random!=NULL)
            {
                temp->next->random = temp->random->next;                
            }
            temp = temp->next->next;
        }
        
        temp = head;
        
        Node *ans = new Node(0);
        Node *t = ans;
        while(head)
        {
            t->next=head->next;
            t = t->next;
            head->next = t->next;
            head=head->next;
        }
        
        return ans->next;
    }
};
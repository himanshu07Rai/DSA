// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node* modifyTheList(struct Node *head);

void push(struct Node **head_ref, int new_data)
{
  struct Node* new_node = new Node(new_data);
  new_node->next = *head_ref;    
  *head_ref = new_node;
}

void printList(struct Node *head)
{
    if (!head)
        return;
   	while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL;
		while(n--){
			int a;
			cin>>a;
			push(&head, a);
		}
		head = modifyTheList(head);
		printList(head);
	}
    return 0;
}

// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
struct Node* modifyTheList(struct Node *head)
{
    //add code here.
    Node* temp = head;
    stack<int> s;
    int len = 0;
    while(temp)
    {
        s.push(temp->data);
        len++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0;i<len/2;i++)
    {
        temp->data = temp->data-s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}
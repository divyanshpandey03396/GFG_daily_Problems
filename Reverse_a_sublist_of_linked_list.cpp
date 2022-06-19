// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseList(Node* head){
        if(!head||!head->next)
            return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* then = curr->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=then;
            if(then)
                then=then->next;
        }
        return prev;
    }
    
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        int i=1;
        Node* iter=head;
        Node* prev=NULL;
        while(i<m&&iter){
            prev=iter;
            iter=iter->next;
            i++;
        }
        if(!iter)
            return head;
        Node* to_rev=iter;
        while(i<n&&iter){
            iter=iter->next;
            i++;
        }
        Node* then=NULL;
        if(iter){
        then = iter->next;
        iter->next=NULL;
        }
        
        
        to_rev=reverseList(to_rev);
        if(prev)
        prev->next=to_rev;
        else{
            head=to_rev;
        }
        while(to_rev->next){
            to_rev=to_rev->next;
        }
        to_rev->next=then;
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends
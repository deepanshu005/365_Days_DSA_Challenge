// CPP DSA Love Babbar 450
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* reverse( struct Node* head ) {// Function to reverse the LL
        Node* prev = NULL;
        Node* curr = head;
        Node* frwd = head->next;
        while( curr ){
            curr->next = prev;
            prev = curr;
            curr = frwd;
            if( frwd )
                frwd = frwd->next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second){
    // lets reverse both the LinkedLists
        Node* t1 = reverse(first);
        Node* t2 = reverse(second);
        Node *dummy = new Node(-1);
        Node *temp = dummy;

        int carry = 0;
        // Applying concept of mergingtwo LL in a new LL
        while( t1 and t2 ){
            int sum = (t1->data) + (t2->data) + carry;
            carry = sum/10;
            sum = sum%10;
            Node *newNode = new Node(sum);
            temp->next = newNode;
            temp = temp->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while( t1 ){
            int sum = (t1->data) + carry;
            carry = sum/10;
            sum = sum%10;
            Node *newNode = new Node(sum);
            temp->next = newNode;
            temp = temp->next;
            t1 = t1->next;
        }
        while( t2 ){
            int sum = (t2->data) + carry;
            carry = sum/10;
            sum = sum%10;
            Node *newNode = new Node(sum);
            temp->next = newNode;
            temp = temp->next;
            t2 = t2->next;
        }
        while( carry ){
            Node *newNode = new Node(carry%10);
            carry = carry/10;
            temp->next = newNode;
            temp = temp->next;
        }
        return reverse(dummy->next);
     // reverse the final linked List   
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

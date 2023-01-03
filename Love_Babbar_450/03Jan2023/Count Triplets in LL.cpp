// CPP DSA Love BAbbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++
int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    unordered_map<int,int> m;// Simply creating map and putting data of visited nodes
    Node* node = head;
    int count=0;
    while( node->next ) {
        Node* temp = node->next;
        while( temp ) {
            if(m[ x-(node->data)-(temp->data) ] > 0) 
                count++;
            temp=temp->next;
        }
        m[node->data]++;
        node=node->next;
    }
    return count;
} 

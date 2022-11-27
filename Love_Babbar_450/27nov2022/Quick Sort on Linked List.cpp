// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */
//you have to complete this function
void insertAtTail(node* &head,node* &tail,int val){
    node* new_node = new node(val);

    if(head==NULL){
        head=new_node;
        tail=new_node;
        return;
    }

    tail->next=new_node;
    tail=new_node;
}

// void print(node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }

node* quickSort(node* head) {
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }

    node* pivot = new node(head->data);

    node* lefthead =NULL;
    node* lefttail =NULL;
    node* righthead =NULL;
    node* righttail = NULL;

    node* walk = head->next;
    while(walk!=NULL){

        if(walk->data<pivot->data){
            insertAtTail(lefthead,lefttail,walk->data);
        }

        else{
            insertAtTail(righthead,righttail,walk->data);
        }

        walk = walk->next;
    }
    lefthead = quickSort(lefthead);
    righthead = quickSort(righthead);

    walk = lefthead;    
    if(walk!=NULL){
        while(walk->next!=NULL){
            walk = walk->next;
        }
    }
    
    if(walk==NULL){
        pivot->next = righthead;
        return pivot;
    }

    walk->next =pivot;
    pivot->next = righthead;
    
    return lefthead;
}

void quickSort(struct node **headRef) {
    *headRef = quickSort(*headRef);   
}

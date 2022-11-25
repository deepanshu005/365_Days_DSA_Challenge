// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n1 = 0, n2 = 0, diff = 0;
    Node *tmp1 = head1, *tmp2 = head2;
    
    while(tmp1 != NULL) {
        ++n1;
        tmp1 = tmp1->next;
    }
    while(tmp2 != NULL) {
        ++n2;
        tmp2 = tmp2->next;
    }
    
    if(n1 >= n2) {
        diff = n1 - n2;
        tmp1 = head1;
        tmp2 = head2;
    }
    else {
        diff = n2 - n1;
        tmp1 = head2;
        tmp2 = head1;
    }
    
    while(tmp1 != NULL && tmp2 != NULL) {
        if(diff > 0) {
            tmp1 = tmp1->next;
            --diff;
        }
        else {
            if(tmp1 == tmp2)
                return tmp1->data;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    return -1;
}

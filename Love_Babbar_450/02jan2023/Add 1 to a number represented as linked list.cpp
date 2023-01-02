// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    //if the last node is 9 then we need to look for a node lwss than 9 closer to 9 on left side so that it can handle carry
    // 
    public:
    Node* addOne(Node *head) {
        Node *temp = head;
        Node *prev = head;// help to hold the node just before 9
        while( temp->next ){// means humaare paas tail aa jaaegi temp mein
            if( (temp->data < 9) and (temp->next->data == 9) )
                prev = temp;
            
            temp = temp->next;
        }
        if( temp->data < 9 ){// ydi last node 9 se km h to direct +1 kr do
            (temp->data)++;
            return head;
        }
        (prev->data)++;
        prev = prev->next;
        while( prev ){
            prev->data = 0;
            prev = prev->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends

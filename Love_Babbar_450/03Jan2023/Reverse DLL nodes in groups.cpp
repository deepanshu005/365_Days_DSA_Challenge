// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/
Node* reverseDLLInGroups(Node* head, int k)
{    
    if( !head )
        return head;
    Node* curr = head;
    Node* temp = NULL;
    Node* prv = NULL;
    
    int count = 0;
    while(count < k && curr != NULL){
        temp = curr -> next;
        curr -> next = prv;
        curr -> prev = temp;
        prv = curr;
        curr = temp;
        count++;
    }
    if(temp!=NULL)
      head->next=reverseDLLInGroups(temp,k);
    return prv;
}

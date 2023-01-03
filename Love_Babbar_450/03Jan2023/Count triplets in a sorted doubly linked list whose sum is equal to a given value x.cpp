// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x){
    DLLNode* temp = head;
    int count = 0;
    while( temp->next ){
        temp = temp->next;
    }// temp eill be pointing the last node of LL after loop completion
    DLLNode* k = head;// first node
    
    while( k!=temp->prev ){
        DLLNode* i = k->next;// 2nd node
        DLLNode* j = temp;// last node
        while( i->data < j->data ){
            if( (k->data)+(i->data)+(j->data) == x ){
                i = i->next;
                j = j->prev;
                count++;
            }
            else if( (k->data)+(i->data)+(j->data) < x ){
                i = i->next;
            }
            else
                j = j->prev;
        }
        k = k->next;
    }
    return count;
}  

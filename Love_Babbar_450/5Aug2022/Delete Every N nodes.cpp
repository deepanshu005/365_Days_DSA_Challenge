// CPP DSA CN Lec 9
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *skipMdeleteN(Node *head, int M, int N){
	if( head==NULL || N==0 )	// N==0 means ek bhi node delete nhi krni
        return head;
    //This line will e executed when we have to delete atleat on node and length of traversing is zero
    if( M==0 )	// M==0 means saari node delete krni h
        return NULL;
    Node *temp = head;
	Node *prev=NULL; 	// Prev will add new nodes after after deleting n nodes
    while( temp!=NULL ){	// in eacjh iteration we will be trversing m nodes and deleting n nodes
        int m = M;
        int n = N;
        while( m>0 && temp!=NULL ){	// traversing m nodes
            prev = temp;
            temp = temp->next;
            m--;
        }
        while( n>0 && temp!=NULL ){	// Deleting n nodes 
            prev->next = temp->next;
            temp = temp->next;
            n--;
        }
    }
    return head;
}

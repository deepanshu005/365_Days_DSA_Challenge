//CPP DSA CN Lec-8
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
// Tail recursion
Node *removeDuplicates(Node *head){
    if( head==NULL || head->next==NULL )	// base case
        return head;
    if( head->data == head->next->data ){
        head->next = head->next->next;
        return removeDuplicates( head );
    }
    else
        head->next=removeDuplicates( head->next );
    return head;
}
a

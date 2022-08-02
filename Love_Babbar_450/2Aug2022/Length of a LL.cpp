// CPP DSA CN Lec-8
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

int length(Node *head){
    int count = 0;
    Node *temp = head;
    while( temp != NULL ){ 	// If there is no element in the LL then while loop will not be executed
        temp = temp->next;
        count++;
    }
    return count;
}

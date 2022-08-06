// CPP DSA CN Lec-9
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
Node *bubbleSort(Node *head)
{
	// Write your code here
     int count = 0;
     Node* start = head;
     Node* curr = NULL;
     Node* trail = NULL;
     Node* temp = NULL;
     //get cnt(size) of linked list
     while (start != NULL) {
         start = start->next;
         count++;
     }
     for (int i = 0; i < count; ++i) {
         //set curr and trail at the start node
         curr = trail = head;
         while (curr->next != NULL) {
             //compares curr and its next
             if (curr->data > curr->next->data) {
                 //swaps pointers for curr & curr->next
                 temp = curr->next;
                 curr->next = curr->next->next;
                 temp->next = curr;
                 //setup pointers for the head and trail if applicable
                 if (curr == head)
                     head = trail = temp;
                 else
                     trail->next = temp;
                 curr = temp;
             }
             //advance pointers
             trail = curr;
             curr = curr->next;
         }
     }
    return head;
}

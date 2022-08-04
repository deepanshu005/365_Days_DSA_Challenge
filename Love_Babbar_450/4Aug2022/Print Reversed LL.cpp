// DSA CN Lec 8
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

void printReverse(Node *head){	
    if( head == NULL ) // Base case
        return;
    printReverse( head->next );
	cout<<head->data<<" ";	//Printing data of each node, head recursion hence small calculations will be done while returning from the base case
}

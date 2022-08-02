// CPP DSA Cn Lec-8
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

Node *appendLastNToFirst(Node *head, int n){
    if( head==NULL || n<=1 )
        return head;
    Node *tail = head;
    int Count = 1;	// Counting the total number of nodes in hte given LL
    while( tail->next != NULL ){
		tail = tail->next;
        Count++;
    }
    //After completion of loop tail will reach to the last node
    //Now breaking the LL from (Count-n)
    Node *temp = head;
    while( (Count-n-1)>0 ){	// since temp is already at the 1st node hence we have to subtract 1 from (count-n)
        temp = temp->next;
        Count--;
    }
    Node *OldHead = head;
    head = temp->next;
    tail->next = OldHead;
    temp->next = NULL;
    // we dont need to free the temp, tail, OldHead because these are statically allocaterd notdynamically hence their scope is just on iteration
    //If we try to free them them TLE will pop
    return head;
}

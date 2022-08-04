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

int findNodeRec(Node *head, int n){
    if( head==NULL )	// base case when the required element is not present or there is no node in LL or the head reaches to the tail of LL
        return -1;
    if( head->data == n)
        return 0;
    int ans = findNodeRec( head->next, n );
    if( ans==-1 )	// If element not found
        return ans;
    else 
        return ans+1;	// if element found
}

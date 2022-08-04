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
//Approach amintaing four pointers, two pointersfor each LL i.e., Ehead and Etail for even LL and OHead and OTail for odd LL
Node *evenAfterOdd(Node *head){
	if( head==NULL || head->next==NULL )	// Base case
        return head;
    Node *OHead = NULL;
	Node *OTail = NULL;
    Node *EHead = NULL;
    Node *ETail = NULL;
    while( head!=NULL ){
        if( (head->data)%2 ){	//If head ka data is odd
            if( OHead==NULL ){	// if Odd LL is empty
            	OHead=head;
                OTail=head;
        	}
            else{
            	OTail->next = head; 
            	OTail = head;
            }
        }
        else{	// if head ka data is even 
            if( EHead==NULL ){	// If even LL is still empty
            	EHead=head;
                ETail=head;
        	}
            else{
            	ETail->next = head;
            	ETail = head;
            }
        }
        head = head->next;
    }
    if( OHead==NULL )	// If only Even LL contains nodes
        return EHead;
    if( EHead==NULL )// If only Odd LL contains nodes
        return OHead;
    // Making tails of both LL as NULL to break both LLs
    //Actually there is no need to Make NULL to both Tails but we dont want to check whichever's next is not NULL hence made NULL to both tails
    OTail->next = NULL;
    ETail->next = NULL;
    OTail->next = EHead;
    return OHead;
}

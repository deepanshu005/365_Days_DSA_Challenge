// CPP DSA CN Lec 9
Node *reverseLinkedList(Node *head) {//This function will return the head of reversed LL of given LL
    if( head==NULL || head->next==NULL )
        return head;
    // The function will be executed further only when the LL containe atleast one node
    Node *prev = NULL;
    Node *curr = head;
    Node *frwd = head->next;
    while( frwd != NULL ){
        curr->next = prev;	// Breking Forward connection and Making backward connection
        prev = curr;
        curr = frwd;
        frwd = frwd->next;
    }
    curr->next = prev;	//Breaking and making the tail connection of LL
    return curr;
}
Node *kReverse(Node *head, int k){
	if( head==NULL || head->next==NULL || k<=1 )
        return head;
    Node *temp = head;
    Node *dee = NULL;
    Node *raj = NULL;
    Node *NextHead = NULL;
    head = NULL;
    while( temp != NULL ){
        int m = k;
        Node *newHead = temp;
        while( m>1 && temp !=NULL ){
            temp = temp->next;
            m--;
        }
        if(temp == NULL){	// for remainig elements elements less in muber of k
            dee->next = reverseLinkedList(newHead);
            return head;
        } 
        NextHead = temp->next;
        temp->next = NULL;
        if( dee!=NULL )	/// for first time
        	dee->next = reverseLinkedList( newHead );    
    	else
            dee = reverseLinkedList( newHead );
        raj = dee;
        while( dee->next!=NULL )
            dee = dee->next;
        dee->next = NextHead;
        if( head==NULL ){
            head = raj;
        }
        else
            dee->next = NextHead;
        
        temp = NextHead;
    }
    return head;
}

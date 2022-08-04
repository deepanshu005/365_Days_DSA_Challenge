// CPP DSA CN Lec 8
// Approach is breaking the given LL in two halves and putting the 2nd half part in new LL and then reversing the 2nd oneand then comparing each element of both LL 
Node *ReturnRevLL( Node *head ){	//This function will return the head of reversed LL of given LL
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
// This function returns the middle Node of given LL
Node *SecondHalf( Node *head ){
    if( head->next==NULL )	// Base case
        return NULL;
    Node *slow = head;	// Slow will traverse the LL by 1 node (consecutively) whereas
    Node *fast = head;	// Fast will traverse the LL by 2 (alternatively) such that whenever Fast reaches the tail then Slow will be at middle node
    while( fast->next!=NULL && fast->next->next!=NULL ){//Ydi fast ka next NULL h to Compiler fast ke next ke next ka Check hi nhi krega
    	slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
// this function was asked in the question which eventually returns true if the the LL is Palindrome
bool isPalindrome(Node *head){
    if( head==NULL || head->next==NULL )	// base case
        return true;
    // Further function will be executed only if LL contains atleast 1 Node
    Node *Second = ReturnRevLL(SecondHalf(head));	// initially SecondHAlf is called which will return the middle node to other function named  ReturnRevLL
    // Second is the head node of 2nd Half reversed LL 
    while( Second!=NULL ){	// Now comparing the each corresponding node of both the LL
        if( head->data != Second->data )
            return false;
        head = head->next;
        Second = Second->next;
    }
    return true;
}

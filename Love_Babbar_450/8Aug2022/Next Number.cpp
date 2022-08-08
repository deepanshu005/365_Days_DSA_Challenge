// CPP DSA CN Test 2
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */if(head->next==NULL)
    {
        if(head->data==9)
        {    head->data=0;
        	Node *x=new Node (1);
        
        	x->next=head;
       	 head=x;
        }
        else
            head->data++;
        
        return head;
    }
    Node *pn=NextLargeNumber(head->next);
    
    if(head->next->data==0 && pn->data==1)
    {  
         if(head->data==9)
        {    head->data=0;
        	Node *x=new Node (1);
        
        	x->next=head;
       	    head=x;
        }
        else
            head->data++;
        
        delete pn;
        return head;
    }
        
    else
    { 
        return head;
    }
    
}
    

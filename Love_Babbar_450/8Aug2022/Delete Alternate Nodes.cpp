//CPP DSA CN Test 2
/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/
void deleteAlternateNodes(Node head[]) {
    //Write your code herevoid   
     if(head==NULL)
        return;
      Node *prev = head;
    Node *node = head->next;
 
    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->next = node->next;
 
        /* Free memory */
        free(node);
 
        /* Update prev and node */
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}




// My self Deepanshu Rajput
// I want to be a very very skilled engineer

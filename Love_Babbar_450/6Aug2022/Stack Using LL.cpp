// CPP DSA CN Lec 10
/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack {
	// Define the data members
    Node *head; 	// Each entry of stack contains two data members First is Node of LL and other is count till that entry
    int count;
   public:
    Stack() {	// Constructor
    	head = NULL;
       	count = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return count;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return count==0;
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode = new Node(element);
    	newNode->next = head;
       	head = newNode;
       	count++;
    }

    int pop() {	//returns the top most element that is head of LL and delete that head
        if( count == 0 )	// If stack is empty 
            return -1;
        int ans = head->data;
        Node *temp = head;
        head = head->next; // removing head from LL
        count--;
        free(temp);	// Deleting head
        return ans;
    }

    int top() {	// just returns the data of top most element that is data of head
        if( count==0 )
            return -1;
        return head->data;
    }
};

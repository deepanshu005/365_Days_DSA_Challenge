// CPP DSA Love Babbar 450
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    // Approach 
    // Just change the sign of the visited node
    bool detectLoop(Node* head){
        if( !head )
            return false;
        while( head ){
            if( (head->data)>=0 )
                head->data = (head->data)*(-1);
            else
                return true;
            head = head->next;
        }
        return false;
    }
};

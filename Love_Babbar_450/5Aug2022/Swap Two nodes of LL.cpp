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
// 0 based indexing
// this code will not work if i or j greater than the length of LL
Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if (i < 0 || j < 0 || i == j)
        return head;

    if (j < i)
        std::swap(i,j);

    Node *pp1 = head;
    while (pp1 && i-- > 0)
    {
        pp1 = (pp1)->next;
        --j;
    }

    Node *pp2 = pp1;
    while (pp2 && j-- > 0)
        pp2 = (pp2)->next;

    if (pp1 && pp2)
    {
        std::swap(*pp1, *pp2);

        std::swap((pp1)->next, (pp2)->next);
    }

    return head;
}

// CPP DSA CN Lec 12
/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
 queue<BinaryTreeNode<int> *>q;
    q.push(root);
    vector<Node<int>*>v;
    
    if(root == NULL){
        return v;
    }
    
    while(q.size()!=0){
   Node<int>*head=NULL;
    Node<int>*tail=NULL;
        int count=q.size();
        while(count>0){
            BinaryTreeNode<int> *front=q.front();
            if(front -> left != NULL){
                q.push(front->left);
            }
            if(front -> right != NULL){
                q.push(front->right);
            }
            q.pop();
          if(head==NULL){
              Node<int>* temp = new Node<int>(front->data);
              head = temp; tail = temp;
          }
            else{
                Node<int>* temp = new Node<int>(front->data);
                tail->next=temp;
                tail=temp;
            }
            count--;
        }
        v.push_back(head);
    }
    
    return v;
}










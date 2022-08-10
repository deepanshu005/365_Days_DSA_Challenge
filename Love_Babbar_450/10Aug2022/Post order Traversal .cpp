// CPP DSA CN Lec 11 continued
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void printPostOrder(TreeNode<int>* root) {
    if( root==NULL )		return;
// Since we have to print post order means root first then its node hence we are using head recursion means reching at the leaf first then printing while returning
    for( int i=0; i<root->children.size(); i++ )
        printPostOrder( root->children[i]);
	cout<<root->data<<" ";
    return;
}

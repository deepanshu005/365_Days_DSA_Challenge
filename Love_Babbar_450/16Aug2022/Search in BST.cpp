// CPP DSA CN Lec 13
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if( root==NULL )		return false;
    
    if( k == root->data )		return true;
    if( k> root->data )
    return	  searchInBST( root->right, k);
    if( k< root->data )
    return    searchInBST( root->left, k);
    

}

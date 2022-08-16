//CPP DSA CN Lec 13
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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if( root==NULL )		return;
  
    if( root->data > k1 )
        elementsInRangeK1K2( root->left, k1, k2 );
    	
    
    if( root->data >=k1 && root->data <=k2 ){
        cout<<root->data<<" ";
    }
    if( root->data < k2 )
        elementsInRangeK1K2( root->right, k1, k2 );
    
}

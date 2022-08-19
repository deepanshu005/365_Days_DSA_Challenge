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
BinaryTreeNode<int>* helper(int *input, int SI, int EI){
    if( SI>EI )		return NULL;
    int mid = (EI+SI)/2;    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root->left = helper( input, SI, mid-1);
    root->right = helper( input, mid+1, EI);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {

    return helper( input, 0, n-1);
}

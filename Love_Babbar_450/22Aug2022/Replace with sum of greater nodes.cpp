//CPP DSA CN Lec 13
/**********************************************************

	Following is the Binary Tree Node class structure

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

***********************************************************/

int replaceWithLargerNodesSumhelper(BinaryTreeNode<int> *root, int sum){
    if (root == NULL) {
        return	0; 
}
    int rsum = replaceWithLargerNodesSumhelper (root->right, sum); 
  	int x = root->data;
    root->data = sum + 	root->data + rsum;  
  	int lsum = replaceWithLargerNodesSumhelper(root->left, root->data);
    return lsum + x  + rsum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replaceWithLargerNodesSumhelper(root,0);
}

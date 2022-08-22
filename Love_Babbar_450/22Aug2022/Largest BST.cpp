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
#include<climits>
class BST
{
    public:
 int minimum;
    int maximum;
    bool isBST;
    int height;
    
    int getheight()
    {
        return height;
    }
    
    
};

BST largestBSTSubtreehelper(BinaryTreeNode<int>* root)
{
    
    if(root == NULL)
    {
        BST x;
    x.minimum = INT_MAX;
    x.maximum = INT_MIN;
    x.isBST = true;
    x.height = 0;
    return x;
        
        
    }
    
    /*
if(root -> left == NULL && root-> right == NULL)
    															//	we can use this as well
{
    BST x;
    x.minimum = root -> data;
    x.maximum = root -> data;
    x.isBST = true;
    x.height = 1;
    return x;
}
    
  */  
    
    BST leftOutput = largestBSTSubtreehelper(root-> left);
    BST rightOutput = largestBSTSubtreehelper(root -> right);
    
    BST x;
    
    if(leftOutput.isBST && rightOutput.isBST && leftOutput.maximum < root -> data && rightOutput.minimum > root->data){
    
    x.minimum = min( root-> data , min(leftOutput.minimum , rightOutput.minimum));
    x.maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    x.isBST = true;
    x.height = max(leftOutput.height , rightOutput.height) + 1;
    return x;
    } 
    
    x.height = max(leftOutput.height, rightOutput.height);
    x.isBST = false;
    x.minimum = min( root-> data , min(leftOutput.minimum , rightOutput.minimum));
    x.maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    return x;
    
    
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
BST curr =  largestBSTSubtreehelper(root);
    return curr.getheight();
}








/////////////// sum of greater nodes




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

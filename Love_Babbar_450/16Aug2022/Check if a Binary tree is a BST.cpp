//CPP DSA Cn Lec 13
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

#include <limits.h>

bool helper(BinaryTreeNode<int>* root, int max = INT_MAX, int min = INT_MIN){
    if(root == NULL){
        return true;
    }
    
    if(root->data > max || root->data < min){
        return false;
    }
    bool leftAns = helper(root->left, root->data, min);
    bool rightAns = helper(root->right, max, root->data);
    return leftAns && rightAns;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return false;
    }
 	
    return helper(root);
}

// bool isBST(BinaryTreeNode<int> *root) {
// 	if( root==NULL )	return	false;
    
//     if( root->left==NULL && root->data < root->right->data )		return isBST(root->right);
//     if( root->right==NULL && root->data >root->left->data )		return isBST(root->left);
    
//     if(root->left != NULL && root->right != NULL && root->data >root->left->data && root->data <root->right->data){
//         bool left = isBST(root->left);
//         bool right = isBST(root->right);
//         return left && right;
//     }
//     return false;
// }

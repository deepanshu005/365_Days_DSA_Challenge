// CPP DSA CN Lec 12
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
#include<bits/stdc++.h>
int height(BinaryTreeNode<int>* root) {
  	if( root==NULL )	return 0;
    
    int Leftsmallans = height(root->left);
    int Rightsmallans = height(root->right);
    return max(Leftsmallans, Rightsmallans) + 1;
    
}
bool isBalanced(BinaryTreeNode<int> *root) {
    if( root==NULL )	return true;
	int Lheight = height(root->left);
    int Rheight = height(root->right);
    int ans = abs(Lheight-Rheight);
    if(ans>1)	return false;

    return isBalanced(root->left)&&isBalanced(root->right);
}

// CPP DSA ove Babbar 450
#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
// Preorder mtlb phle root node and then left child and then right child
void preorder( BinaryTreeNode* root, vector<int> &vec, int &index ){
    if( !root )
        return;
    root->data = vec[index++];
    preorder( root->left, vec, index );
    preorder( root->right, vec, index );
}
void inorder( BinaryTreeNode* root, vector<int> &vec ){
    if( !root )
        return;
    inorder( root->left, vec );
    vec.push_back(root->data);
    inorder( root->right, vec );
}
BinaryTreeNode* convertBST(BinaryTreeNode* root){
    if( !root )
        return root;
	vector<int> vec;
    inorder( root, vec );// we are doing inorder bcoz inorder traversal of BST gives 
    //elements in non-decreasing fashion
    int index = 0;
    preorder( root, vec, index );
    
    return root;
    
}

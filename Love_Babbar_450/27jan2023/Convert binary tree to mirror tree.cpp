// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/

void mirrorTree(BinaryTreeNode<int> *root) {
    if(!root)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    swap(root->left, root->right);
}

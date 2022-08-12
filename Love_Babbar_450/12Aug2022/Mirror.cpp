// CPP DSA CN Lec 12
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
    if(root==NULL)		return;
    BinaryTreeNode<int>*Left=root->left;
    root->left=root->right;
    root->right=Left;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    return ;
}

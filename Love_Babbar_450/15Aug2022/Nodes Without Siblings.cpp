/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if( root==NULL )	return ;
    if( root->left == NULL && root->right==NULL )	return;
    if( root->left == NULL || root->right==NULL ){
        cout<<root->data<<" ";
        return;
    }	
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}*/
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return;
    if(root->left==NULL && root->right!=NULL)
        cout<<root->right->data<<" ";
    if(root->right==NULL && root->left!=NULL)
        cout<<root->left->data<<endl;
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);

}

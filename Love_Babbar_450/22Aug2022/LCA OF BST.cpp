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

int getLCA(BinaryTreeNode <int>* root , int a, int b)
{
    if(root==NULL)
        return -1 ;
    if(root->data==a||root->data==b)
        return root->data;
    int l=getLCA(root->left,a,b);
    int r=getLCA(root->right,a,b);
    if(l!=-1&&r!=-1)
        return root->data;
   return  (l!=-1)?l:r;
}

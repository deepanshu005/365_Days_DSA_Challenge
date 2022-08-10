CPP DSA Lec 11
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include<climits>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if( root==NULL )	// edge case
        return root;
    TreeNode<int>* deep = root; //Assuming our root node to be max of all and deep node will hold the max of all nodes which we will be returning
    for( int i=0; i<root->children.size(); i++ ){
    	TreeNode<int>* raj = maxDataNode(root->children[i]);// raj will contain the max data node of its of tree
        if( deep->data <= raj->data )
            deep = raj;
    }
    return deep;
}

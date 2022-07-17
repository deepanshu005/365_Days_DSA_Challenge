//Coding ninjas DSA Lecture 11 
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

int getLeafNodeCount(TreeNode<int>* root) {
    if( root==NULL )
        return 0;
    int count = 0;	// cpunting the total number of leaf nodes
    if( root->children.size()==0 )	// base case whenever function reaches at leaf node
        return count+1;	// hence counting that leafnode and returning count+1
    for( int i=0; i<root->children.size(); i++ )
        count += getLeafNodeCount( root->children[i]);
    return count;
}

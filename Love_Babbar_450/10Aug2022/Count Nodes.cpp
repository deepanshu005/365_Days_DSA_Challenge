// CPP DSA CN Lec 11 continued
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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if( root==NULL )
        return 0;
    int count = 0;

// Making head recursive calls
    for( int i=0; i<root->children.size(); i++ ){
        count += getLargeNodeCount(root->children[i],x);                               
    }
    if( root->data > x)
	    return count+1;
    else 
    	return count;
}

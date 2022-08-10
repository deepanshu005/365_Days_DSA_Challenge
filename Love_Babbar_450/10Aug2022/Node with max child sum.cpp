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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
	if( root==NULL || root->children.size()==0 )
        return root;
    TreeNode<int>* Max = root;
    for( int i=0; i<root->children.size(); i++ ){
        
    }
}

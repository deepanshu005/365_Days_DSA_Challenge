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
TreeNode <int>* helper( TreeNode<int>* root, int d ){
     root->data = d;
    for( int i=0; i<root->children.size(); i++ ){
      
       	helper( root->children[i], d+1 );
    }
     
    return root;
}
void replaceWithDepthValue(TreeNode<int>* root) {
    root = helper( root, 0);
    
}

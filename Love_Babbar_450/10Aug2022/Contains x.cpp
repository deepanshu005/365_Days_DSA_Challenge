// CPP DSA CN Lec 11 Continued
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

bool isPresent(TreeNode<int>* root, int x) {
    if( root==NULL )
        return false;
    if( root->data == x )	// base case whenever element found
        return true;
    for( int i=0; i<root->children.size(); i++ ){
        if( isPresent(root->children[i], x) )	// if element found only then we will return otherwise we wouldnt return anything and we will iterste to next children
            return true;
    }
    return false;// ydi milte to return true ho chuka hota, ab kuch nhi mila to return false krna pdega
}

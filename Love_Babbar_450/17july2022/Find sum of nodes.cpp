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
// just assume only two steps that is we have given one root and its children vector 
// we have to perform our calculations on that node and its children vector
// rest eill be handeled by recursion itself
int sumOfNodes(TreeNode<int>* root) {
    if( root==NULL )	// edge case
        return 0;
    int sum = root->data;
    for( int i=0 ;i<root->children.size(); i++ ){ // base case will handeled by children size of vector of root node
        sum +=  sumOfNodes(root->children[i]);
    }
    return sum;
}

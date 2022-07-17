// Lecture 11 coding ninjas DSA
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

int getHeight(TreeNode<int>* root) {
    if( root==NULL )
        return 0;
    int height = 0;	// takes care of the max height of all the nodes visited yet
    	// height of current node will be stored in small Height and 
    //the overall max height will be stored in height and hencw we are taking max of smallHeight and height
    for( int i=0; i<root->children.size(); i++ ){
        int smallHeight = getHeight(root->children[i]);
        height = max( smallHeight, height );
    }
    return height+1; // +1 is for the current node itself
}

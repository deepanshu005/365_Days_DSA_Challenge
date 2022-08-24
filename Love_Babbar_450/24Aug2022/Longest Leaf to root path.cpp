CPP DSA CN Test 3
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;



    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
	if (root==NULL)
        return NULL;
    if(!root->left && !root->right){
        vector<int>* out=new vector<int>();
        out->push_back(root->data);
        return out;
    }
    vector<int>* la=longestPath(root->left);
    vector<int>* ra=longestPath(root->right);
    if(!la){
        ra->push_back(root->data);
        return ra;
    }
    else if(!ra){
        la->push_back(root->data);
        return la;
    }
    else{
        if(la->size()<ra->size()){
            ra->push_back(root->data);
        	delete la;
            return ra;
        }
        else{
            la->push_back(root->data);
        	delete ra;
            return la;
        }
    }
}


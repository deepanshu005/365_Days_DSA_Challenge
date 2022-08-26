// CPP DSA CN Test 3
// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};


***************/


#include<vector>
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    // Write your code here
	if(root==NULL || root->numChildren()==0)
        return NULL;
    vector<int> i;
    for(int x=0;x<root->numChildren();x++){
        TreeNode<int> *c=root->getChild(x);
        if(c->numChildren()==0)
            i.push_back(x);
    }
    for(int x=i.size()-1;x>=0;x--){
        int j=i[x];
        root->removeChild(j);
    }
    for(int x=0;x<root->numChildren();x++){
    	TreeNode<int> *c=removeLeafNodes(root->getChild(x));
        if(c==0)
            root->removeChild(x);
    }
    return root;
    
}


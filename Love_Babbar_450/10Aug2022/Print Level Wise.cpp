// CPP DSA CN Lec 11
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
#include<queue>
void printLevelWise(TreeNode<int>* root) {
    if( root==NULL )
        return;
    queue<TreeNode<int>*> q;
    q.push(root);
    while( !q.empty() ){
        TreeNode<int> *top = q.front();
        int n = top->children.size();
        cout<<top->data<<":";
        int i=0;
        for( i=0; i<n-1; i++ ){
            q.push(top->children[i]);
            cout<<top->children[i]->data<<",";
        }
        if( i== n-1 ){
        	cout<<top->children[i]->data<<endl;
        	q.push(top->children[i]);
        	
        }
        else
            cout<<endl;
        q.pop();
    }
}

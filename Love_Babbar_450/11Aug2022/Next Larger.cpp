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
// #include<vector>
// #include<queue>
// TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
// 	vector <TreeNode<int>*> v;
//     for( int i=0; i<root->children.size(); i++ ){
//         v.push_back(root->children[i]);
//         getNextLargerElement( root->children[i], x);
//     }
//     for(int i =0; i<v.size(); i++ )
//     	if( v[i]->data>x)	return v[i];
// }


#include<vector>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    
    if(root==NULL)		 return root;
       
    TreeNode<int>* ans=NULL;
    
    if(root->data > x)	 	ans = root;
 
    else	 ans = NULL;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>* temp = getNextLargerElement(root->children[i], x);
        
        if(ans==NULL)		 ans=temp;
           
        if(temp!=NULL && temp->data < ans->data)	ans=temp;       
    }
return ans;
}


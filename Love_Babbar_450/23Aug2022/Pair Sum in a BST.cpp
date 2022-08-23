//CPP DSA CN Lec 13
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

void f(BinaryTreeNode<int> *root,vector<int> &v)
{if(root==NULL)
    return;
 
    f(root->left,v);
    v.push_back(root->data);
    f(root->right,v);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    vector<int>v;
    f(root,v);
    int i=0;
    int j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]<s)
            i++;
      else  if(v[i]+v[j]>s)
            j--;
        else if(v[i]+v[j]==s)
        {
            if(v[i]>v[j])
                cout<<v[j]<<' '<<v[i];
            else
                cout<<v[i]<<' '<<v[j];
            cout<<endl;
            i++;
            j--;
        }
            
    }
    
}

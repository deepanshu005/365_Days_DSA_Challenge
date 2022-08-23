// CPP DSA CN Lec 13
/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
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

***********************************************************/
/*void depth(BinaryTreeNode<int> *root, int k) { 
    if(root == NULL) {
        return;
    }
    if(k == 0) { 
        cout << root -> data << endl; 
        return;
    }
    depth(root -> left, k - 1);
    depth(root -> right, k - 1);
}
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
    if (root == NULL) 
        return -1;
    
    if (root -> data == target) {
        depth(root, k);
        return 0;
    }
    
    int leftD = nodesAtDistanceKHelper(root -> left, target, k);
    
    if (leftD != -1) { 
        if (leftD + 1 == k) {
            cout << root -> data << endl;
        }
        else
            depth(root -> right, k - leftD - 2);
        return 1 + leftD;
    }
    int rightD = nodesAtDistanceKHelper(root -> right, target, k);
    if (rightD != -1) {
        if (rightD + 1 == k) {
            cout << root -> data << endl;
        } 
        else
            depth(root -> left, k - rightD - 2);
        return 1 + rightD;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    
    nodesAtDistanceKHelper(root, node, k);
	
}
*/
/* LCA 	Of binary tree*/
/*int getLCA(BinaryTreeNode <int>* root , int a, int b)
{
    if(root==NULL)
        return -1 ;
    if(root->data==a||root->data==b)
        return root->data;
    int l=getLCA(root->left,a,b);
    int r=getLCA(root->right,a,b);
    if(l!=-1&&r!=-1)
        return root->data;
   return  (l!=-1)?l:r;
}*/

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

//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends

#include<bits/stdc++.h>
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/
/*
Tree for sample test case
//6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
                     50
                   /    \
                 30      70
                /  \     / \
              20   40   60  80
*/
void get( Node *root, vector<Node*> &vec){// Inorder traversal
    if( root==NULL )
        return;
    get( root->left, vec );
    vec.push_back(root);
    get( root->right, vec );
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if( root==NULL ){
        pre = NULL;
        suc = NULL;
        return;
    }
    vector<Node *> vec;
    get( root, vec );
    int n = vec.size();
    
    if( vec[0]->key >= key ){// Hnadling edge case
        pre = NULL;
        if( vec[0]->key == key and n>1 ){// ydi leftmost child, key k baraabar h and 1 se jyaada elements h vec m
               suc = vec[1];
               return;
        }
        if( vec[0]->key == key and n==1){// ydi leftmost child, key k baraabar h and 1 hi element h vec m
               suc = NULL;
               return;
        }
        suc = vec[0];//ydi key leftmost element se bhi km h
        return;
    }
    if( vec[n-1]->key <= key ){// Hnadling edge case
        suc = NULL;
        if( vec[n-1]->key == key and n>1 ){// ydi rightmost element, key k baraabr h and ek se jyaada elements h vector m
               pre = vec[n-2];
               return;
        }
        if( vec[n-1]->key == key and n==1){// ydi rightmost element, key k baraabr h and ek hi element h vector m
               pre = NULL;
               return;
        }
        pre = vec[n-1];//ydi key righmost element se bhi jyaada h
        return;
    }
    for( int i=0; i<n-1;i++ ){
        if( key>vec[i]->key and key<vec[i+1]->key ){
            pre = vec[i];
            suc = vec[i+1];
            return;
        }
        if( vec[i]->key == key){// ydi koi element key k baraaabar hoga
            pre = vec[i-1];
            suc = vec[i+1];
            return;
        }
    }
    return;
}

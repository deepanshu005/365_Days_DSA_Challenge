// CPP DSA Love Babbar 450
//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
// Approach is simple 
// Take an element from preorder and search that element in sub inorder coz the left portion will be in 
// left subtree and right sub inorder will be right subtree
class Solution{
    public:
    Node* healer( int in[], int pre[], int &index, int i, int j,int n ){
        if( i>j )
            return NULL;
            
        int element = pre[index++];
        Node* root = new Node(element);
        int position;
        for( int k=i; k<=j; k++ ){// searching the element in Inorder
            if( in[k] == element ){
                position = k;
                break;
            }
        }
        
        root->left = healer( in, pre, index, i, position-1, n );
        root->right = healer( in, pre, index, position+1, j, n );
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n){
        int preOrderIndex = 0;
        Node *ans = healer( in, pre, preOrderIndex, 0, n-1, n );
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends

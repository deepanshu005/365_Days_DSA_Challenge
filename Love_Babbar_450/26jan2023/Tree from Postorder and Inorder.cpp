// CPP DSA Love Babbar 450
//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

    Node* healer( int in[], int post[], int &index, int i, int j,int n ){
        if( i>j )
            return NULL;
            
        int element = post[index--];
        Node* root = new Node(element);
        int position;
        for( int k=i; k<=j; k++ ){// searching the element in Inorder
            if( in[k] == element ){
                position = k;
                break;
            }
        }
        // Here the right potion will be bilded first then left will be builded
        root->right = healer( in, post, index, position+1, j, n );
        root->left = healer( in, post, index, i, position-1, n );
        return root;
    }
    
    Node* buildTree(int in[],int post[], int n){
        int postOrderIndex = n-1;
        Node *ans = healer( in, post, postOrderIndex, 0, n-1, n );
        return ans;
    }

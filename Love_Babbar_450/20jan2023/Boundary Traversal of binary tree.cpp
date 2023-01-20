// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // Traversing the left nodes except the leaf node
    void traLeft( Node*root, vector<int> &vec ){
        if( !root or (!root->left and !root->right) )// excluding leaf nodes
            return;
        
        vec.push_back(root->data);
        if(root->left)
            traLeft(root->left, vec);
        
        else
            traLeft(root->right, vec);
        
    }
    // Traversing the leaf nodes
    void traLeaf( Node*root, vector<int>&vec ){
        if( !root ){
            return;
        }
        if( !root->left and !root->right ){
            vec.push_back( root->data );
        }
        traLeaf(root->left, vec);
        traLeaf(root->right, vec);
    }
    // Traversing the right nodes except the leaf node
    void traRight( Node*root, vector<int> &vec ){
        if( !root or (!root->left and !root->right) )// excluding leaf nodes
            return;
        
        if(root->right)
            traRight(root->right, vec);
        
        else
            traRight(root->left, vec);
        
        vec.push_back(root->data);// Since we wanna push while returning hence Backtracking 
    }
    
    vector <int> boundary(Node *root){
        vector<int> ans;
        if( !root )
            return {};
        
        ans.push_back( root->data );// pushing the root node
        
        traLeft(root->left, ans);// getting left nodes
        
        // We are separating left and right subtree because there might be skewed tree
        // if we don't make such a partition then left and right will be printed twice
        traLeaf(root->left, ans);
        traLeaf(root->right, ans);
        
        traRight(root->right, ans);// getting right side lwhile going upward
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).
class Solution {
  public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(!node)
            return 0;
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        return max( lHeight,rHeight )+1;
    }
    pair<int,int> diaFast( Node* root ){
        if( !root )
            return {0,0};
        pair<int, int> lefti = diaFast(root->left);
        pair<int, int> righti = diaFast(root->right);
        
        int leftDia = lefti.first;
        int rightDia = righti.first;
        int Dia = lefti.second + righti.second + 1;
        
        pair<int, int> ans;
        ans.first = max(max(leftDia,rightDia), Dia);
        ans.second = max( lefti.second, righti.second ) + 1;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diaFast(root).first;
    }
};

/*
    // Function to return the diameter of a Binary Tree.
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(!node)
            return 0;
    // left ko bolo wo apne height calculate krke laayega 
    // right ko bolo wo apne height calculate krke laayega 
    // and dono ko jo maximum hoga usme +1 kr do for root node and return 
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        return max( lHeight,rHeight )+1;
    }
    // For each node we are visiting each node two times one for finding height
    // and other for finding diameter eventually TC will be O(N*N)
    // we can optimize this by simultaneously calculating the height and diamter
    int diameter(Node* root) {
        if(!root)
            return 0;
        // left ko bolo wo apna diameter nikaal k laayega 
        // right ko bolo wo apna diameter nikaal k laayega 
        // and hum apna diameter nikaal lete h 
        // aur unme se jo max hoga ussey return kr denge
        int maxi = height(root->left) + height(root->right)+1;
        int lefti = diameter(root->left);
        int righti = diameter(root->right);
        return max(max(lefti, righti), maxi);
    }*/

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends

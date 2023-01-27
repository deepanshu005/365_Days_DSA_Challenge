// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void flatten(Node *root){
        Node* curr = root;
        Node* prev = NULL;
        while(curr){
            if(curr->left){
                prev = curr->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        return;
    }
    /*
    // Time Complexity: O(n)
    // Auxiliary Space: O(n)
    void preOrder( Node* root, vector<Node*> &vec ){
        if(!root)// Base Case
            return;
        
        vec.push_back(root);
        preOrder( root->left, vec );
        preOrder( root->right, vec );
    }
    void flatten(Node *root){
        vector<Node*> vec;
        preOrder( root, vec );
        int n = vec.size();
        
        for( int i=0; i<n-1; i++ ){
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }
        vec[n-1]->left = NULL;
        vec[n-1]->right = NULL;
        return;
    }*/
};

//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}

// } Driver Code Ends

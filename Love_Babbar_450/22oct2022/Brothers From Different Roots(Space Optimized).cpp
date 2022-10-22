//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    
public:
    int countPairs(Node* root1, Node* root2, int x){
        int count=0;
        Node*top1 =nullptr;
        Node*top2=nullptr;
        stack<Node*>st1;
        stack<Node*>st2;
        st1.push(root1);
        st2.push(root2);
        
        Node*temp1 = root1->left;
        Node*temp2 = root2->right;
        
        while((!st1.empty() or temp1!=nullptr) and (!st2.empty() or temp2!=nullptr)){
            if( temp1!=nullptr ){
                st1.push(temp1);
                temp1=temp1->left;
            }
            
            if(temp2!=nullptr){
                st2.push(temp2);
                temp2=temp2->right;
            }  
            
            if(temp1==nullptr and temp2==nullptr){
                top1 = st1.top();
                top2 = st2.top();
                if( (top1->data + top2->data) == x ){
                    count++;
                    st1.pop();
                    st2.pop();
                    temp1 = top1->right;// previously we iterate on temp1=temp1->left;
                    temp2 = top2->left;// previously we iterate on  temp2=temp2->right;
                }
                else if ((top1->data + top2->data) < x) {
                    st1.pop();
                    temp1 = top1->right;
                }
                else {
                    st2.pop();
                    temp2 = top2->left;
                } 
            }
        }
    return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends

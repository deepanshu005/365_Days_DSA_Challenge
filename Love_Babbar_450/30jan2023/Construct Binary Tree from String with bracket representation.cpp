// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    // Approach is simple get the data for curr node and by running while  loop
    // And then make the new node and connect with either left or right(if left already exists)
    // and siimulataneously push these nodes to stack also
    Node *treeFromString(string str){
        stack<Node*> st;
        int i = 0;
        string s = "";
        while( str[i]!= '(' and str[i]!= ')' )
            s += str[i++];
        
        Node* root = new Node(stoi(s));
        st.push(root);
        int n = str.length();
        while( !st.empty() and i<n ){
            if( str[i]=='(' ){
                i++;
                string x = "";
                while( str[i]!= '(' and str[i]!= ')' )
                    x += str[i++];
                Node* temp = new Node(stoi(x));
                if( st.top()->left ){
                    st.top()->right = temp;
                }
                else
                    st.top()->left = temp;
                st.push(temp);
            }
            else if( str[i]==')' ){
                st.pop();
                i++;
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

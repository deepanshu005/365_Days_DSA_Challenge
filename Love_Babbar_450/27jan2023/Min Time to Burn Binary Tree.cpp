// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
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
// Time Complexity: O(NlogN)
// Auxiliary Space: O(N)
class Solution {
  public:
  // performing mapping of each node corresponding to the respective parents
    Node* mapping( Node* root, map<Node*, Node*>& mp, int target ){
        Node* res = NULL;
        queue< Node* > q;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp->data==target)// we got the required node
                res = temp;
            
            if(temp->left){
                mp[temp->left] = temp;  
                q.push(temp->left);  
            }  
            if(temp->right){
                mp[temp->right] = temp;  
                q.push(temp->right); 
            }
        }
        return res;
    }
    
    int burnTree( Node*root, map<Node*, Node*>& mp ){
        map<Node*, bool>vis;// map to count if the node is visited or not
        queue<Node*>q;
        int ans = 0;
        q.push(root);
        vis[root] = true;
        while( !q.empty() ){
            bool flag = 0;// to see if we have visited some new node or not
            int size = q.size();
            for( int i=0; i<size; i++ ){
                Node* front = q.front();
                q.pop();
                // Visiting the left of front node
                if(front->left and !vis[front->left] ){
                    flag = 1;
                    q.push(front->left);
                    vis[front->left] = 1;
                }
                // Visiting the right of front node
                if(front->right and !vis[front->right] ){
                    flag = 1;
                    q.push(front->right);
                    vis[front->right] = 1;
                }
                // Visiting the parent of front node
                // phle deakha front ka parent exist krta h ki nahi
                // if it exists then check if its parent has been visited or not
                if( mp[front] and !vis[mp[front]] ){
                    flag = 1;
                    vis[mp[front]] = 1;
                    q.push(mp[front]);
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
    
    int minTime(Node* root, int target) {
        // as we are can move only to hte child of nodes hence to move to parent we have to precompute them
        map<Node*, Node*> mp;// creating a map to store the parents of each node
        Node* req = mapping(root, mp, target);// getting the node corresponding the target
        
        return burnTree( req, mp);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends

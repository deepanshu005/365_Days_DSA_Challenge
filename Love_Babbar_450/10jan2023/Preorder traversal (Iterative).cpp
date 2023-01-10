// CPP DSA Love Babbar 450
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
// As we generally do traversal using recursion which is basically a stack 
// Which means we can also implement traversal using stack iteratively
class Solution{
    public:
    vector<int> preOrder(Node* root){
        vector<int> vec;
        stack<Node*> st;
        st.push(root);
        
        while( !st.empty() ){
            Node* temp = st.top();
            st.pop();
            
            vec.push_back(temp->data);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return vec;
    }
};

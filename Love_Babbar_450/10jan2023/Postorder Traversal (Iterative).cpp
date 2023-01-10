// CPP DSA love Babbar 450
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
  public:
    vector<int> postOrder(Node* node) {
        vector<int> vec;
        stack<Node*> st;
        st.push(node);
        while(!st.empty()) {
            Node* temp = st.top();
            if(temp -> left) {
                st.push(temp -> left);
                temp -> left = NULL;
            }
            else if(temp -> right) {
                st.push(temp -> right);
                temp->right = NULL;
            }
            else{
                vec.push_back(temp -> data);
                st.pop();
            }
        }
        return vec;
    }
};

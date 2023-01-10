// CPP DSA Love Babbar 450
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root){
        stack<Node*>st;
        vector<int> vec;
        Node *temp = root;
        while( true ){
            if(temp){
               st.push(temp); 
               temp = temp->left;
            }
            else{
                if( st.empty() )
                    break;
                temp = st.top();
                st.pop();
                vec.push_back(temp->data);
                temp = temp->right;
            }
        }
        return vec;
    }
};

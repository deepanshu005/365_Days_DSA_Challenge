// This code has runtime error
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void search(TreeNode*root, int key,TreeNode* &node  ){
        if( root==NULL ){
            return;
        }   
        if( root->left==NULL and root->right!=NULL ){
            if( root->right->val == key ) {
                node = root;
                return;
            }
            search(root->right,  key, node );
        }
        else if( root->left!=NULL and root->right==NULL ){
            if( root->left->val == key ) {
                node = root;
                return;
            }
            search(root->left,  key, node );
        }
        else if(root->left!=NULL and root->right!=NULL and (root->left->val==key or root->right->val==key )){
            node = root;
            return;
        }
         search(root->left, key, node );
         search(root->right, key, node );
    }
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root==NULL )
            return root;
        if( root->val==key and root->left==NULL and root->right==NULL )
            return NULL;
        
        if( root->val==key and (root->left!=NULL or root->right!=NULL) ){
            TreeNode *dummy = new TreeNode(key+1);
            dummy->left = root;
            return deleteNode( dummy, key);
        }
        
        TreeNode *req = NULL;
        search( root, key, req);
        if( req==NULL )
            return root;
        int last = 0;
        TreeNode *temp = NULL;
        if( req->left->val==key ){
            if( req->left->left==NULL and req->left->right==NULL ){
                req->left=NULL;
                return root;
            }
            if( req->left->left!=NULL and req->left->right==NULL ){
                req->left = req->left->left;
                return root;
            }
            if( req->left->left==NULL and req->left->right!=NULL ){
                req->left = req->left->right;
                return root;
            }
            if( req->left->left!=NULL and req->left->right!=NULL ){
                temp = req->left->left;
                req->left = req->left->right;
                TreeNode *node = req->left;
                while( node->left or node->right){
                    node = node->left;
                }
                node->left = temp;
                return root;
            }
        }
        if( req->right->val==key ){
            if( req->right->left==NULL and req->right->right==NULL ){
                req->right=NULL;
                return root;
            }
            if( req->right->left!=NULL and req->right->right==NULL ){
                req->right = req->right->left;
                return root;
            }
            if( req->right->left==NULL and req->right->right!=NULL ){
                req->right = req->right->right;
                return root;
            }
            if( req->right->left!=NULL and req->right->right!=NULL ){
                temp = req->right->right;
                req->right = req->right->left;
                TreeNode *node = req->right;
                while( node->left or node->right){
                    node = node->right;
                }
                node->right = temp;
                return root;
            }
        }
        // rightmost( req, last );
        return root;
        
    }
};

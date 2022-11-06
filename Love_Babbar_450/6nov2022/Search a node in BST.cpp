#include <iostream>
using namespace std;
 
// // Binary tree node
// struct Node {
//     int data;
//     struct Node *left, *right;
//     Node(int data)
//     {
//         this->data = data;
//         left = right = NULL;
//     }
// };
bool ifNodeExists(struct Node* node, int key)
{
    if (node == NULL)
        return false;
 
    if (node->data == key)
        return true;
 
    bool res1 = ifNodeExists(node->left, key);
    // node found, no need to look further
    if(res1) return true;
 
    /* node is not found in left,
    so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key);
 
    return res2;
}

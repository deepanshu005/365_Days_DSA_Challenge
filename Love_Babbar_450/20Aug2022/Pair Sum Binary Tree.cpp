// CPP DSA CN Lec 13
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void inorder(BinaryTreeNode<int> *root, vector<int> &arr) {
  
   if (root == NULL)
        return;
    arr.push_back(root->data);
    inorder(root -> left,arr);
    
    inorder(root -> right,arr);
    
    
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> arr;
    
    inorder(root,arr);
    
    sort(arr.begin(), arr.end());
    int last = arr.size()-1;
    int first = 0;
    
    while(first < last) {
       if(arr[first] + arr[last] > sum){
            last--;
        }
        else if(arr[first] + arr[last]  < sum){
            first++;
        } 
        else{
            cout<<arr[first]<<" "<<arr[last]<<endl;
            first++; 
            last--;
       }
    }
} 

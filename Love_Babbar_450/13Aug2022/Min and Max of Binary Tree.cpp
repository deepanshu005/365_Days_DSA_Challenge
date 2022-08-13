//CPP DSA CN Lec 12
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
// pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
// 	if(root==NULL)
//         return;
    
//         // pair<int, int> p;
//         // p.first = 0;
//         // p.second = 0;
//         // return p;
    
//     pair<int, int> leftAns = getMinAndMax(root->left);
//     pair<int, int> rightAns = getMinAndMax(root->right);
//     int Lmin = leftAns.first;
//     int Lmax = leftAns.second;
//     int Rmin = rightAns.first;
//     int Rmax = rightAns.second;
    
//     int Min = min(Lmax, Rmax);
//     int Max = max(Lmax, Rmax);
//     pair<int, int> p;
//         p.first = Min;
//         p.second = Max;
//         return p;
    
// }
#include<bits/stdc++.h>
using namespace std;

void trav(BinaryTreeNode<int>* root,int &minx,int &maxx){
    
    if(root==NULL)
        return;
    minx=min(minx,root->data);
    maxx=max(maxx,root->data);
    
    trav(root->left,minx,maxx);
    trav(root->right,minx,maxx);
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    int minx=INT_MAX;
    int maxx=INT_MIN;
    
    trav(root,minx,maxx);
    
    pair<int, int> p;
    if(root==NULL){
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    p.first=minx;
    p.second=maxx;
    return p;
}



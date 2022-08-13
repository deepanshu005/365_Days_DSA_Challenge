// CPP DSA CN Lec 12
/***********************************************************
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
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pos, int inS, int inE, int posS, int posE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pos[posE];
	int rootIndex;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPosS = posS;
	int lPosE = lInE - lInS + lPosS;
	int rPosE = posE -1;
	int rInS = rootIndex +1;
	int rInE = inE;
    int rPosS = rInS-rInE+rPosE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);

	root->right = buildTreeHelper(in, pos, rInS, rInE, rPosS, rPosE);
    root->left = buildTreeHelper(in, pos, lInS, lInE, lPosS, lPosE);
	return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeHelper(inorder, postorder, 0, inLength - 1, 0, inLength - 1);
}

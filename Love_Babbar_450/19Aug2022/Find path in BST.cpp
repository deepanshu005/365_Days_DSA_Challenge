// CPP DSA CN Lec 13
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

#include <vector>
vector<int>* getPath(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getPath(root->left, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getPath(root->right, data);
	if (rightOutput != NULL) {
			rightOutput->push_back(root->data);
			return rightOutput;
	} else {
		return NULL;
	}
}

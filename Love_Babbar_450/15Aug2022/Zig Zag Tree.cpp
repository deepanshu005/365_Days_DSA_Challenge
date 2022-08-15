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
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
template <typename T>
class Node{
    public:
        T data;
        Node<T> * next;
        Node(T data){
            this->data=data;
            this->next=nullptr;
        }
};
template <typename T>
class Nodelist{
    public:  // Exposing Everything which is not the best way. But the idea over
        //  here is only to modularize the code
        Node<T> *start, *end;
        Nodelist(Node<T> *p=nullptr)
            :start(p), end(p)
        {
            if(p==nullptr) return;
            p->next = nullptr;
        }
        void pushnode(Node<T> *p)
        {
            if(p==nullptr) return;
            p->next = nullptr;
            if(start==nullptr)
            {
                /* First Node to insert */
                start = end = p;
                return;
            }
            end->next = p;
            end = p;
        }
        void popEndnode()
        {
            if(end==nullptr) return;
            if(end==start)
            {
                /* last node to return */
                delete end;
                start = end = nullptr;
                return;
            }
            Node<T> *curr=start;
            while(curr->next!=end) curr = curr->next;
            curr->next = nullptr;
            delete end;
            end = curr;
        }
};
vector<Node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> result;
    if(root==nullptr) return result;
    queue<BinaryTreeNode<int>*> *inputQ, *outputQ, *temp;
    inputQ = new queue<BinaryTreeNode<int>*>();
    outputQ = new queue<BinaryTreeNode<int>*>();
    inputQ->push(root);
    /* Here we want to add a link list into result */
    Node<int> *ptr = new Node<int>(root->data);
    ptr->next=nullptr;
    result.push_back(ptr);
    do
    {
        //nodelist<int> *list = new nodelist<int>();
        Nodelist<int> list;
        while(!inputQ->empty())
        {
            BinaryTreeNode<int> *curr = inputQ->front();
            inputQ->pop();
            if(curr->left!=nullptr)
            {
                outputQ->push(curr->left);
                ptr = new Node<int>(curr->left->data);
                list.pushnode(ptr);
            }
            if(curr->right!=nullptr)
            {
                outputQ->push(curr->right);
                ptr = new Node<int>(curr->right->data);
                list.pushnode(ptr);
            }
        }
        temp = inputQ;
        inputQ = outputQ;
        outputQ = temp;
        result.push_back(list.start);
    } while(!inputQ->empty());
    // Clean up: delete queues created on heap
    delete inputQ;
    delete outputQ;
    return result;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
     vector<Node<int>*> v = createLLForEachLevel(root);
    int size= v.size();
    for(int i=0; i<size; i++)
    {
        Node<int> *list = v[i];
        if(i%2==0)
        {
            /* Print the list in forward order */
            while(list!=nullptr)
            {
                cout << list->data << ' ';
                list = list->next;
            }
            cout << endl; 
        }
        else
        {
            vector<int> stack;
            /* Print the list in backward order */
            while(list!=nullptr)
            {
                stack.push_back(list->data);
                list = list->next;
            }
            for(int j=stack.size()-1; j>=0; j--)
                cout << stack[j] << ' ';
            cout << endl; 
        }
    }
}

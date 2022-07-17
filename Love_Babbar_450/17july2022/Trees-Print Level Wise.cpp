// Coding ninjas DSA Lecture 11 question 1
void printLevelWise(TreeNode<int>* root) {
	if( root==NULL )// edge case not a base case
        return;
	queue<TreeNode<int>*> q;	// creating a queue named q which contains the unvisited TreeNode pointers
    q.push(root);	// pushing the root in q for tghe first time
    while( !q.empty() ){	// loop will keep running until it got empty
     	cout<<q.front()->data<<":";
    	int n = q.front()->children.size();	//  contains the size of children vector of front node of q
    	int i=0;
        for( i=0; i<n-1 ; i++ ){	// traversing till last second node of children vector of front node of queue
			cout<<q.front()->children[i]->data<<",";
            q.push(q.front()->children[i]);
        }
        if( n!=0 ){	// this line will be executed whenever the front node contaisn atleast one child and that was not handeled by above for loop
        	cout<<q.front()->children[i]->data<<endl;
        	q.push(q.front()->children[i]);   
        }
        else	// executed only when the front node has no child
            cout<<endl;
        q.pop();
    }
}

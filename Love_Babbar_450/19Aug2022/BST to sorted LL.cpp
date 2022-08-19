//CPP DSA CN Lec 13
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	
      if ( root==NULL){
            return NULL;
        }
        
Node<int> * lefttreenode = NULL;
Node<int> * righttreenode = NULL;

Node<int> * newroot = new Node<int> (root->data);
    
if ( root->left!=NULL){
    
    lefttreenode = constructLinkedList (root->left);
    
    //if ( root->right != NULL){
    righttreenode = constructLinkedList ( root->right);
        
    
    Node<int>* temp = lefttreenode;
        
    if ( temp!= NULL){
        while ( temp->next != NULL ){
                temp = temp->next;}
                    
        temp->next = newroot;
        newroot->next = righttreenode;
        return  lefttreenode;
    }
}


if ( root->right != NULL){
           
righttreenode = constructLinkedList ( root->right);
 
newroot ->next = righttreenode;
return newroot;
}
    
return newroot;
}

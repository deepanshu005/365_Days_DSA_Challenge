// class pairclass{
// 	public:
//   	TreeNode<int>* max;
//     TreeNode<int>* secondmax;
//     public:
//     pairclass(TreeNode<int>* first ,TreeNode<int>* second){
//         this->max=first;
//         this->secondmax=second;
//     }
// };

// pairclass* helper(TreeNode<int>* root){
//     pairclass* maxpair=new pairclass(root,NULL);
//     for(int i=0;i<root->children.size();i++){
//         pairclass* temp=helper(root->children[i]);
        
//         //first case
//         if(maxpair->secondmax==NULL && temp->secondmax==NULL){
//             if(maxpair->max->data>temp->max->data){
//                 maxpair->secondmax=temp->max;
//             }
//             else{
//                	maxpair->secondmax=maxpair->max;
//                 maxpair->max=temp->max;
//             }
            
//         }
//         //second case
//         else if(maxpair->secondmax==NULL&&temp->secondmax!=NULL){
//             if(maxpair->max->data>temp->max->data){
//                 maxpair->secondmax=temp->max;
//             }
//             else{
                
//                 if(maxpair->max->data>temp->secondmax->data){
//                     maxpair->secondmax=maxpair->max;
//                     maxpair->max=temp->max;
//                 }
//                 else{
//                     maxpair->max=temp->max;
//                     maxpair->secondmax=temp->secondmax;
//                 }
//             }
//         }
//         //third case
//         else if(temp->secondmax==NULL&&maxpair->secondmax!=NULL){
//             if(maxpair->max->data>temp->max->data){
//                 if(maxpair->secondmax->data<temp->max->data){
//                     maxpair->secondmax=temp->max;
//                 }
//             }
//             else{
                
//                 maxpair->secondmax=maxpair->max;
//                 maxpair->max=temp->max;
//             }
//         }
        
//         //fourth case
//         else{
//             if(maxpair->max->data>temp->max->data){
//                 if(maxpair->secondmax->data<temp->max->data){
//                     maxpair->secondmax=temp->max;
//                 }
//             }
//             else{            
//                 if(maxpair->max->data>temp->secondmax->data){
//                     maxpair->secondmax=maxpair->max;
//                     maxpair->max=temp->max;
//                 }
//                 else{
//                     maxpair->max=temp->max;
//                     maxpair->secondmax=temp->secondmax;
//                 }
//             }
//         }
        
//      }
//     return maxpair;
// }
// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
//     pairclass *ans=helper(root);
//     return ans->secondmax;
// }


//=================TA
void helper(TreeNode<int>* root, int &greater, int &smaller){
    if(root->children.size()==0 && root->data>greater){
        smaller=greater;
        greater=root->data;
    }
    if(root->children.size()==0 && root->data>smaller && root->data<greater){
        smaller=root->data;
    }
    for(int i=0; i<root->children.size(); i++){
        helper(root->children[i], greater, smaller);
        if(root->data>greater){
            smaller=greater;
            greater=root->data;
        }
        else if(root->data>smaller && root->data<greater){
            smaller=root->data;
        }
    }
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root==NULL){return root;}
    // help ans(root->data);
    int smaller=INT_MIN;
    int greater=INT_MIN;
    helper(root, greater, smaller);

    TreeNode<int>* final_ans = new TreeNode<int>(smaller);
    return final_ans;
}

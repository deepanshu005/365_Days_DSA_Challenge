// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
// Question is aapke paas ek array h named A and ek stack h 
// Inn dono ka use krke aapka ek array bnaana h B jaisa
// Ydi bn skta h to return 1 else 0
// pushing in stack will only be in sequence means first we have to push elements from index 0 then 1 then 2 and so on
// but pop from stack can be done at any instant
    int isStackPermutation(int n,vector<int> &a,vector<int> &b){
        int i=0, j=0;
        stack<int> st;
        
        while(i<n && j<n){
            if(a[i]!=b[j]){//  ydi element brabar nahin hai to stack m push krte jaaenge jb tak baraabr nahin mil jaate
                st.push(a[i]);
                i++;
            } 
            else{
                st.push(a[i]);
                i++;
                while(!st.empty() && st.top()==b[j]){// ydi barabar h to pop krte jaaenge jb tk stack khaali ya different nahin mil jaate
                    st.pop();
                    j++;
                }
            }
        }
        return st.empty();
    }
};
/* My Approach which is absolutely correct
// same approach but coding style is bit different
int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> st;
        st.push(-1);
        int i = 0;
        int j = 0;
        while( i<N ){
            
            while( (i<N) and (A[i]!=B[j]) and (st.top()!=B[j]) ){
                st.push(A[i]);
                i++;
            }
            if( (i<N) and (A[i]==B[j]) ){
                i++;
                j++;
            }
            else if( st.top()==B[j] ){
                st.pop();
                j++;
            }
        }
        while(!st.empty()){
            if( st.top()==B[j] ){
                j++;
            }
            st.pop();
        }
        if( j<N )
            return 0;
        return 1;
    }*/

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends

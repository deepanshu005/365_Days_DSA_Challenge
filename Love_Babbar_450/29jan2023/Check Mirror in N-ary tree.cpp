// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Approach is simple we will make a map of type <int, stack<int>>
    // and corresponding to each node we will push the corresponding node of each edge
    // And then traverse the B[] and simltaneously pop thosa corresponding nodes from stack if we got 
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int> > mp;
        // visit only even positions
        for( int i=0; i<2*e; i+=2 ){
            mp[A[i]].push(A[i+1]);
        }
        for( int i=0; i<2*e; i+=2 ){
            if( mp[B[i]].top() != B[i+1] ){
                return 0;
            }
            mp[B[i]].pop();
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends

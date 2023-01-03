// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void heapify( vector<int> &arr, int n, int i ){
        int parent = i;
        int left = 2*i+1;
        int right = 2*i+2;
    
        if( left<n and arr[left]>arr[parent] )
            parent = left;
        if( right<n and arr[right]>arr[parent] )
            parent = right;
    
        if( parent!=i ){// mtlb kush gdbd h ya to left chlld chota h ya fir right child bda h
            swap( arr[parent], arr[i] );
            heapify( arr, n, parent);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        // Since leaf nodes are already heapified hence we will only heapify the parent nodes
        // the parent node of last node i.e (n-1)th will be ((n-1)-1)/2 = (n/2) - 1
        for( int i = (N/2)-1; i>=0; i-- ){
            heapify( arr, N, i );
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends

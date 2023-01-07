// CPP DSA love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // Simply swapping all corresponding elements around middle column i.e (n+1)/2 th column
	    for( int i=0; i<n; i++ ) {
	        for( int j=0; j<(n+1)/2; j++ ) {   
	            swap( arr[i][j], arr[i][n-j-1] );
	        }
	    }
	    // now swapping all elements around left diagonal measn elements with (i>j)
	    for( int i=1; i<n; i++ ) {
	        for( int j=0; j<i; j++ ) {   
	            swap( arr[i][j], arr[j][i] );
	        }
	    }
	    return ;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

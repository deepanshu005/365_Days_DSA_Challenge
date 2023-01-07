// CPP DSA Love babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

// TC : O( NlogM )
// SC : O(1)
    int BS_ceil( vector<int>arr, int i, int j, int x ){

        while( i<=j ){
            int mid = i + (j-i)/2;
            if( arr[mid] ==1 )
                j = mid-1;
            
            else 
                i = mid+1;
        }
        return i;// it will return the first index of 1 in each row
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ansIndex = INT_MAX;
	    int ans = -1;
	    for( int i=0; i<n; i++){
	        if( arr[i][m-1]==0 )
	            continue;
	        int ceilIndex = BS_ceil(arr[i], 0, m-1, 0);

	        if( ansIndex>ceilIndex ){
	            ans = i;
	            ansIndex = ceilIndex;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

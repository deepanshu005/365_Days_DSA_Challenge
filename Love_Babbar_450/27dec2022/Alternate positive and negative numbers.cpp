// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // Simply do vectors bnaaye one for all positives and other for all negatives
	void rearrange(int arr[], int n) {
	    vector<int> vecP;
	    vector<int> vecN;
	    for( int i=0; i<n; i++ ){
	        if( arr[i]>=0 ){
	            vecP.push_back(arr[i]);
	        }
	        else{
	            vecN.push_back(arr[i]);
	        }
	    }
	    int k = 0;
	    int posize = vecP.size();
	    int l = 0;
	    int nesize = vecN.size();
	    int i=0;
	    while( k<posize and l<nesize ){
	        arr[i++] = vecP[k++];
	        arr[i++] = vecN[l++];
	    }
	    while( k<posize ){
	        arr[i++] = vecP[k++];
	    }
	    while( l<nesize ){
	        arr[i++] = vecN[l++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

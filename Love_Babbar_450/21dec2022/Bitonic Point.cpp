// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int peak( int arr[], int i, int j, int n ){
	    int mid = i + (j-i)/2;
	    while( i<=j ){
	        mid = i + (j-i)/2;
	        if( mid>0 and mid<(n-1) ){
	            if( arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1] ){
	                return mid;
	            }
	            else if( arr[mid-1]<arr[mid] ){
	                i = mid+1;
	            }
	            else{
	                j = mid-1;
	            }
	        }
	        else{
	            if(mid==0){
	                if( arr[mid]>arr[mid+1] )
	                    return mid;
	                return mid+1;
	            }
	            if( mid==n-1 ){
	                if( arr[mid]>arr[mid-1] ){
	                    return mid;
	                return mid-1;
	                }
	            }
	        }
	    }
	}
	int findMaximum(int arr[], int n) {
	    int index = peak( arr, 0, n-1, n );
	    return arr[index];
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
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

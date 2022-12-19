// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int BS( int arr[], int i, int j, int n ){
        int prev;
        int next;
        int mid;
        while( j>=i ){
            
            mid = i + (j-i)/2;
            next = (mid+1)%n;
            prev = (mid+n-1)%n;
            if( arr[mid]<=arr[next] and arr[mid]<=arr[prev] ){
                return mid;
            }
            if( arr[mid]>=arr[0] ){
                i = mid+1;
            }
            else if( arr[mid]<=arr[n-1] )
                j = mid-1;
        }
    }
public:	
	int findKRotation(int arr[], int n) {
	    if( arr[0]<arr[n-1] )
	        return 0;
	    return BS( arr, 0, n-1, n );
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

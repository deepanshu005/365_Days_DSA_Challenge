// CPP DSA Love Babbar 450
//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
    static int Bs(int arr[], int start ,int end, int k, char ch ){
    int res = -1;
    while( end >= start ){
        
        int mid = start + (end-start)/2;
        if( arr[mid] == k ){
            if( ch == 'l' ){
                res = mid; 
                end = mid-1;  
            }
            else if( ch == 'r' ){
                res = mid;
                start = mid+1;
            }
        }
        else if( k < arr[mid] ){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;
}
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int a = Bs( arr, 0 , n-1, x, 'l' );
        int b = Bs( arr, 0 , n-1, x, 'r' );
        if( a==-1 )// mtlb element present hi nhi h
            return 0;
        return b-a+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

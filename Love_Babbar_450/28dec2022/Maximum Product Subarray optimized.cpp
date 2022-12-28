//CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    typedef long long ll;
	// Function to find maximum product subarray
	// Approach there can be two possibilities for curr element 
	//either we continue our prev subarray with this curr element
	// or we will start a new subarray from this curr element
	// hence to judge whichever will be beneficial we will take two variables maxi and mini
	long long maxProduct(vector<int> arr, int n) {
	    ll ans = arr[0];
	    ll maxi = arr[0];// maxi will store the curr max possible product
	    ll mini = arr[0];// mini will store the curr min possible product
	    for( int i=1; i<n; i++ ){
	        if( arr[i]<0 ){// udi curr element negative h to swap maxi and mini
	            swap( maxi, mini );// coz multiplying a larger number with negative number makes it smaller 
	        }
	        maxi = max( (ll)arr[i], maxi*arr[i]);
	        mini = min( (ll)arr[i], mini*arr[i]);
	        ans = max( maxi,ans );// stores the max of all products 
	    }
	    return ans;
	}
	/*
		// Function to find maximum product subarray
	// Naive Approach
	// Taking all the subarrrays
	// Test Cases Passed: 
    // 385 /10352
    // Time Limit Exceeded
	long long maxProduct(vector<int> arr, int n) {
        long long prod = 0;
        long long curr = 1;
        if ( n==1 ){
            return arr[0];
        }
        for( int i=0; i<n; i++ ){
            for( int j=i; j<n; j++ ){// Now arr[i..j] is the subarray
                for( int k=i; k<=j; k++ ){
                    curr *= arr[k];
                }
            
            prod = max( prod, curr );
            curr = 1;
            }
        }
        return prod;
	}*/
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue< int, vector<int>, greater<int>> pq;// declaring min heap
	    for( int i=0; i<n; i++ ){
	        pq.push(arr[i]);
	        if( pq.size()>k ){
	            pq.pop();
	        }
	    }// now we will have only k largest elements in the min heap
	    // pushing and poping one by one in the vactor
	    vector<int> ans(k,0);// vector of k size intialised with zero
	    while(!pq.empty()){
	        ans[k-1] = pq.top();// coz we wanna print in decresing order
	        pq.pop();
	        k--;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

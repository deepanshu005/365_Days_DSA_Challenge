// CPP DSA love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k){
        vector <int> ans;
        list<int> q;
        for( int i=0, j=0; j<n; j++ ){
            while( !q.empty() and arr[j]>q.back() ){
                q.pop_back();
            }
            q.push_back( arr[j] );
            if( j-i+1==k ){
                ans.push_back( q.front() );
                if( arr[i]==q.front() ){
                    q.pop_front();
                }
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

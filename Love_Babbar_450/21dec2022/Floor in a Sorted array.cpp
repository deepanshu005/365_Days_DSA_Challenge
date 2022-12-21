// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int BS_floor( vector<long long> arr, long long i, long long j, long long x ){
        long long int mid = i + (j-i)/2;
        int index = -1;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( arr[mid]==x ){
                return mid;
            }
            if( arr[mid]<x ){
                i = mid+1;
                index = mid;
            }
            else{
                j = mid-1;
            }
        }
        return index;
    }
    int findFloor(vector<long long> vec, long long n, long long x){
        return BS_floor( vec, 0, n-1, x );
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends

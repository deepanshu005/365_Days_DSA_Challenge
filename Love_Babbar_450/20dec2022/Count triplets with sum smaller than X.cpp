// CPP DSA Love Babbar 450
// Naive Approach TLE may occur
// Need to be optimized
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long countTriplets(long long arr[], int n, long long sum){
	    sort( arr, arr+n );
	    int count = 0;
	    for( int i=0; i<n-2; i++ ){

	        for( int j=i+1; j<n-1; j++ ){
	            if( arr[i]+arr[j]+arr[j+1] >= sum )
	                break;
	            for( int k=j+1; k<n; k++ ){
	                if( arr[i]+arr[j]+arr[k] < sum )   {
	                    count++;
	                }
	                else
	                    break;
	            }
	        }
	    }
	    return count;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long X ){
	    sort( arr, arr+n );
	    int ans = 0;
	    for( int k=0; k<n-2; k++ ){
	        int i = k+1;
	        int j = n-1;
	        while( i<j ){
	            int sum = arr[k] + arr[i] + arr[j];
	            if( sum < X ){// mtlb humaara sum X se chota h and yhi hum chahte h and hence increment of i
	                ans += (j-i);
	                i++;
	            }
	            else{// mtlb humaara sum bda hence we need to decrease the value of sum hence j--
	                j--;
	            }
	        }
	    }
	    return ans;
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

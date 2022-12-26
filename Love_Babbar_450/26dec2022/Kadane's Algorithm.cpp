// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    // Basically we keep maximum sum and current sum and whenever current sum becomes negative we make it zero
    // the good question arrises how to keep track of that subarray with max sum..?
    
    long long maxSubarraySum(int arr[], int n){
        long long sum = 0;
        long long maxi = arr[0];
        for( int i=0; i<n; i++ ){
            sum+=arr[i];
            maxi = max( maxi, sum );
            if( sum<0 )
                sum = 0;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends

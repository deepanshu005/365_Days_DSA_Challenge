// CPP DSA Love Babbar 450
//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    // no changes 
    // As it is of Allocate min number of pages
  public:
    bool isPossible( int arr[], int n, int k, long long mid ){
        int paintCount = 1;
        long long units = 0;
        for( int i=0; i<n; i++ ){
            if( units + arr[i] <= mid ){
                units += arr[i];
            }
            else{// means we ned to consider one more painter
                paintCount++;
                if( paintCount>k || mid<arr[i] ){
                    return false;
                }
                else{
                    units = arr[i];
                }
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k){
        
        long long totalUnits = 0;
        for( int i=0; i<n; i++ ){
            totalUnits += arr[i];
        }
        long long i = 0;
        long long j = totalUnits;
        long long mid;
        long long ans = -1;// stores the min time
        while( i<=j ){
            mid = i + (j-i)/2;
            if( isPossible(arr, n, k, mid) ){// mid jitne time mein to kr paa rhe h and usssey jyaada time bhi availble hoga to usme to definetly kr hi denge
                ans = mid;
                j = mid-1;// hence decresing the time to get min of all
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends

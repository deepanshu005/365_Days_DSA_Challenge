// CPP DSA Love Babbar 450
//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;
        for( int i=0; i<n; i++ ){
            if( arr[i]<=k ){
                count++;
            }
        }
        int fav = 0;
        for( int i=0; i<count; i++ ){
            if( arr[i]<=k ){
                fav++;
            }
        }
        int infav = count-fav;
        int swaps = infav;
        for( int i=1; i<=n-count; i++ ){
            if( arr[i-1]<=k and arr[i+count-1] > k ){// jo gya wo fav tha lekin jo aaya wo infav h
                fav--;
                infav++;
            }
            if( arr[i-1]>k and arr[i+count-1] <= k ){
                fav++;
                infav--;
            }
            swaps = min( swaps, infav);
        }
        return swaps;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends

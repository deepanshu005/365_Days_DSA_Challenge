// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  // simply the unbounded knapsack
    int cutRod(int price[], int n) {
        int wt[n];
        for( int i=0; i<n; i++ ){
            wt[i] = i+1;
        }
        return knapSack( n, n, price, wt );
    }
    int knapSack(int N, int W, int val[], int wt[]){
        int dp[1001][1001] = {0};
        // memeset( dp, 0, sizeof(dp) );
        for( int i=1; i<N+1; i++ ){
            for( int j=1; j<W+1; j++ ){
                if( wt[i-1] <= j ){
                    dp[i][j] = max( val[i-1] + dp[i][ j-wt[i-1] ], dp[i-1][j] );
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

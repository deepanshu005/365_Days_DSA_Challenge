// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Child prblm of unbounded 01 knapsack problem 
    // changes made are initialisation is 0th row by 0 and 0th column by 1
    // since we have to count the number of ways hence instead of making choice we simply added 
    long long int count( int coins[], int N, int sum ){
        long long int dp[1001][1001] = {0};
        // memeset( dp, 0, sizeof(dp) );
        for( int i=1; i<N+1; i++ )
            dp[i][0] = 1;
        for( int i=1; i<N+1; i++ ){
            for( int j=1; j<sum+1; j++ ){
                if( coins[i-1] <= j ){
                    dp[i][j] = dp[i][ j-coins[i-1] ]+ dp[i-1][j] ;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends

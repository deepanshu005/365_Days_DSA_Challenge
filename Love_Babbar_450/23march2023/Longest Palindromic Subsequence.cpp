// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        string s1 = A;
        reverse( A.begin(), A.end() );
        string s2 = A;
        int x = A.length();
        int y = A.length();
        vector<vector<int>> dp( x+1, vector<int>(y+1,-1));
        
        for( int i=0; i<=x; i++ ){
            for( int j=0; j<=y; j++ )   {
                if( i==0 or j==0 )
                    dp[i][j] = 0;
                else{
                    if( s1[i-1] == s2[j-1] )
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else if(s1[i-1] != s2[j-1] )
                        dp[i][j] = max( dp[i][j-1], dp[i-1][j] );   
                }
            }
        }
        return dp[x][y];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

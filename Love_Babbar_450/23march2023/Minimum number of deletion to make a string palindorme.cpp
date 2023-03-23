// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


    int minDeletions(string A, int n) { 
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
        return (n-dp[x][y]);
    }

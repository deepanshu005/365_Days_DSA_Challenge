// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int minOperations(string s1, string s2) {
	    int x = s1.length();
	    int y = s2.length();
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
        int lcs = dp[x][y];
        int ans = ( s1.length()-lcs) + ( s2.length()-lcs );
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
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends

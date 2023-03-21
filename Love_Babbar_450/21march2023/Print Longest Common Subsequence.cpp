// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

// function to find longest common subsequence

// function to find longest common subsequence
// Memoiazation
// function to find longest common subsequence


// function to find longest common subsequence

// function to find longest common subsequence

// function to find longest common subsequence
// Memoiazation
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
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
        string str = "";
        int i = x;
        int j = y;        
        while( i>0 and j>0 ){
            if( s1[i-1] == s2[j-1] ){
                str += s1[i-1];
                i--;
                j--;
            }
            else{
                if( dp[i][j-1] > dp[i-1][j] ){// left wala bda h
                    j--;
                }
                else
                    i--;
            }
        }
        reverse( str.begin(), str.end() );
        std::cout<< str <<endl;
        return dp[s1.length()][s2.length()];
    }
};

//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends

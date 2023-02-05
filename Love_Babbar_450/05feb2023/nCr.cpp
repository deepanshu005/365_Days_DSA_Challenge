// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{

public:

#define mod 1000000007

    int nCr(int n, int r){

        // code here

       vector<vector<int>>dp(n+1,vector<int>(r+1,0));

        for(int i=0;i<n+1;i++)

        {

            for(int j=0;j<r+1;j++)

            {

                if(i==j || j==0) dp[i][j]=1;

                if(j==1) dp[i][j]=i;

            }

        }

        for(int i=1;i<n+1;i++)

        {

            for(int j=1;j<r+1;j++)

            {

                if(j>i) continue;

               dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;

            }

        }

        return dp[n][r];

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends

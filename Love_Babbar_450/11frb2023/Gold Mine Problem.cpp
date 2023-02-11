// CPP DSA Love Babbaar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i<0 || i>=n  || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        // upwards diagonaly
        int x=arr[i][j]+solve(i-1,j+1,m,n,arr,dp);
        
        // downwards diagonaly
        int y=arr[i][j]+solve(i+1,j+1,m,n,arr,dp);
        
        // right
        int z=arr[i][j]+solve(i,j+1,m,n,arr,dp);
        
        // maximum of all
        int maxgold=max(x,max(y,z));
        return dp[i][j]=maxgold;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int maxi=0;
         for(int i=0;i<n;i++){
            int ans=solve(i,0,m,n,M,dp);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

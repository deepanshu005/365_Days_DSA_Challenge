// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solveMem(string A,string B,string C,int i,int j,int k,vector<vector<vector<int>>>&dp){
    if(i>=A.size() ||j>=B.size()||k>=C.size()){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    if(A[i]==B[j] && B[j]==C[k]){
        int ans=1+solveMem(A,B,C,i+1,j+1,k+1,dp);
        return dp[i][j][k]=ans;
    }
    else{
        int a=solveMem(A,B,C,i+1,j,k,dp);
        int b=solveMem(A,B,C,i,j+1,k,dp);
        int c=solveMem(A,B,C,i,j,k+1,dp);
        return dp[i][j][k]=max(a,max(b,c));
    }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    return solveMem(A,B,C,0,0,0,dp);
}

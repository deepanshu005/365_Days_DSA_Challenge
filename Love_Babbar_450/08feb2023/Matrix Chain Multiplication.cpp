// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
int solve(int arr[],int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            int tempans = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini,tempans);
        }
        return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(101,vector<int>(101,-1));
        int i = 1,j = N-1;
        return solve(arr,i,j,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends

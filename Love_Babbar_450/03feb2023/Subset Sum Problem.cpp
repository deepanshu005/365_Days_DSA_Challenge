// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /* // *********Recursive Approach*********
    bool healer(vector<int>arr, int n, int sum){
        if( sum==0 )    return true;
        if( n==0 )  return false;
        if( arr[n-1] <= sum )
            return healer( arr, n-1, sum-arr[n-1] ) or healer( arr, n-1, sum );
        else
            return healer( arr, n-1, sum );
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return healer( arr, n, sum );
    }
    
    
    // was getting segmentation fault if i use array matrix I dont why thats why i used vector
    // Now its going fine 😊
    // *********Recursion + Memoization*********
    bool healer(vector<int>arr, int n, int sum, vector<vector<int>>& dp){
        if( sum==0 )    return true;
        
        if( n==0 )  return false;
        
        if( dp[n-1][sum] != -1 )
            return dp[n-1][sum];
            
        if( arr[n-1] <= sum )
            return dp[n-1][sum] = healer( arr, n-1, sum-arr[n-1], dp ) or healer( arr, n-1, sum, dp );
        else if( arr[n-1] > sum )
            return dp[n-1][sum] = healer( arr, n-1, sum, dp );
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return healer( arr, n, sum, dp );
    }
    */
    // *********DP*********
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)    dp[i][j]= false;
                if(j==0)    dp[i][j]=true;
            }
        }
        for( int i=1; i<=n; i++ ){
            for( int j=1; j<=sum; j++ ){
                if( arr[i-1] <= j ){
                    dp[i][j] = dp[i-1][ j-arr[i-1] ] or dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

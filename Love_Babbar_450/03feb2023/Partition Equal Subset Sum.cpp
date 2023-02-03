// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int n, int arr[], int sum){
        
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)    dp[i][j]= false;
                if(j==0)    dp[i][j]=true;
            }
        }
        for( int i=1; i<n+1; i++ ){
            for( int j=1; j<sum+1; j++ ){
                if( arr[i-1] <= j ){
                    dp[i][j] = dp[i-1][ j-arr[i-1] ] or dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[]){
        long int sum = 0;
        for( int i=0; i<N; i++ ){
            sum += arr[i];
        }
        if( sum%2==1 )  return 0;
        return isSubsetSum( N, arr, sum/2 );
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends

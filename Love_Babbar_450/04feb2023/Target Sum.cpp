// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {

  public:

    int findTargetSumWays(vector<int>&a ,int target) {

        //Your code here

        int arrsum=0;

        int n=a.size();

        for(int i=0;i<n;i++){

            arrsum+=a[i];

        }

         if(arrsum<target || arrsum+target<0 || (arrsum+target)%2!=0)

         return 0;

        int sum=(arrsum+target)/2;

        int dp[n+1][sum+1];

        for(int i=0;i<n+1;i++){

            for(int j=0;j<sum+1;j++){

                if(i==0)

                dp[i][j]=0;

                if(j==0)

                dp[i][j]=1;

            }

        }

        for(int i=1;i<n+1;i++){

            for(int j=0;j<sum+1;j++){

                if(a[i-1]<=j)

                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];

                else

                dp[i][j]=dp[i-1][j];

            }

        }

        return dp[n][sum];

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends

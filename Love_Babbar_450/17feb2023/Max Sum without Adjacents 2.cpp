// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
   int dp[1000001][2];

  

  int findMaxSum(vector<int>& a){

      int n=a.size();

      if(n==1)return a[0];

      else if(n==2)return a[0]+a[1];

      

      dp[0][0]=dp[0][1]=0;

      dp[1][1]=a[0];

      dp[2][1]=a[0]+a[1];

      dp[2][0]=a[0];

      for(int i=3;i<=n;++i){

          dp[i][1]=a[i-1]+max(a[i-2]+dp[i-2][0],dp[i-1][0]);

          dp[i][0]=max(dp[i-1][0],dp[i-1][1]);

      }

      return max(dp[n][0],dp[n][1]);

  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends

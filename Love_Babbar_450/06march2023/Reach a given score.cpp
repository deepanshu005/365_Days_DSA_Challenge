// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

long long int help(int n,long long int w,vector<int> &a,vector<vector<long long int>> &dp)
{
   if(w==0)
    return 1;
   if(n==0 || w<0)
    return 0;
   if(dp[n][w]!=-1)
    return dp[n][w];
   else
   {
       if(a[n-1]<=w)
       {
           long long int take=help(n,w-a[n-1],a,dp);
           long long int notake=help(n-1,w,a,dp);
           return dp[n][w]=take+notake;
       }
       else
        return dp[n][w]=help(n-1,w,a,dp);
   }
}
long long int count(long long int n)
{
   
   vector<int> a={3,5,10};
   
   //memoization
   // vector<vector<long long int>> dp(4,vector<long long int>(n+1,-1));
   // return help(3,n,a,dp);
   
   
   //tabulation
   vector<vector<long long int>> dp(4,vector<long long int>(n+1));
   for(int i=0;i<=3;i++)
    dp[i][0]=1;
   for(long long int i=0;i<=n;i++)
    dp[0][i]=0;
   for(int i=1;i<4;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(a[i-1]<=j)
           {
               long long int take=dp[i][j-a[i-1]];
               long long int notake=dp[i-1][j];
               dp[i][j]=take+notake;
           }
           else
            dp[i][j]=dp[i-1][j];
       }
   }
   return dp[3][n];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends

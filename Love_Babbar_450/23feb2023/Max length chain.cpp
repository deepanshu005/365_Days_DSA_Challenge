// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    int solve(int indx,int prev,vector<pair<int,int>>&v,int n,vector<vector<int>>&dp){
   if(indx==n){
       return 0;
   }
   if(dp[indx][prev+1]!=-1){
       return dp[indx][prev+1];
   }
   int inc=0;
   if(prev==-1 or v[indx].first>v[prev].second){
        inc=1+solve(indx+1,indx,v,n,dp);
   }
   int exc=solve(indx+1,prev,v,n,dp);
  return dp[indx][prev+1]=max(inc,exc);
   
}
int maxChainLen(struct val p[],int n)
{
//Your code here
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
   v.push_back({p[i].first,p[i].second});
}
sort(v.begin(),v.end());
vector<vector<int>>dp(n,vector<int>(n,-1));
return solve(0,-1,v,n,dp);
}
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends

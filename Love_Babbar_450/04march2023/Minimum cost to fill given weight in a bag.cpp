// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	 int f(int i, int w, int cost[], vector<vector<int>> &dp)
{
    if(w==0)
        return 0;
    if(i==0)
        return cost[0]!=-1 ? w*cost[0] : 1e8;
        
    if(dp[i][w]!=-1)
        return dp[i][w];
    
    int ans = f(i-1,w,cost,dp);
    if(w-(i+1)>=0 && cost[i]!=-1)
       ans = min(ans, cost[i] + f(i,w-(i+1),cost,dp));
    
    return dp[i][w] = ans;
}
int minimumCost(int cost[], int N, int W) 
{ 
    vector<vector<int>> dp(N,vector<int>(W+1,-1));
       return f(N-1,W,cost,dp);
} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends

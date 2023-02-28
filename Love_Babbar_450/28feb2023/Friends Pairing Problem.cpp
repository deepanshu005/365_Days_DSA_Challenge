// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int dp[10002];
    Solution(){
        memset( dp, -1, sizeof(dp));
    }
    int countFriendsPairings(int n) {
        long long M = 1e9+7;
        long long ans = 0;
        if( n<=2 )      
            return n;
        if( dp[n] !=-1 )
            return dp[n];
        else{
            ans = (countFriendsPairings(n-1))%M + (n-1)*(countFriendsPairings(n-2)%M)%M;
            return dp[n] = ans%M;
        }
    }
    /*
    Recursive Approach
    int countFriendsPairings(int n) {
        if( n<=2 )      
            return n;
        long long M = 1e9+7;
        long long ans = countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2);
        return ans%M;
    }*/
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends

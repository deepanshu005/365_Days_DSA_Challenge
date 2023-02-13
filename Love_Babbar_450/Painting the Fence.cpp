// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
       if(n == 1) return (k);
       int mod = (int)1e9 + 7;
       long long int same = k * 1;
       long long int diff = (k * (k-1)) % mod;
       long long int total = (same + diff) % mod;
       
       for(int i = 3; i <= n; i++){
           same = diff * 1;
           diff = (total * (k-1)) % mod;
           total = (same + diff) % mod;
       }
       
       return total;
   }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends

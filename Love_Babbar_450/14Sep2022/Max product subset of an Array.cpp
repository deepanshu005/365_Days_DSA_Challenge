// CPP DSA Love Babbar 450
//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        if( n==1 )
            return a[0];
        sort( a.begin(), a.end() );
        int pos = 0;
        int neg = 0;
        long long ans = 1;
        int i=0;
        int h = pow(10,9)+7;
        while( a[i]<0 and i<n ){
            neg++;
            i++;
        }
        if( n==2 && neg%2==1 )
            return max(a[0],a[1]);
        
        if( neg%2==0 ){
            for( i=0; i<n; i++ ){
                if( a[i]!=0 )
                    ans = ((long)ans*a[i])%h;
            }    
        }
        else{
            for( i=0; i<n; i++ ){
                if( i==neg-1 )//because neg-1 will be having the max negative number
                    continue;
                if( a[i]!=0 )
                    ans = ((long)ans*a[i])%h;
                
            }  
        }
        return ans%h;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends

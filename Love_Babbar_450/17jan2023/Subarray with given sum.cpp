// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s){
        long long sum = 0;
        if( s==0 )
            return {-1};
        for( int i=0, j=0; j<=n; ){
            if( sum==s ){
                return {i+1,j};
            }
            else if( sum<s ){
                sum+= arr[j];
                j++;
            }
            else if( sum>s ){
                sum -= arr[i];
                i++;
            }
        }
        return {-1};
    }
    
    /* Showing TLE coz i used auxilliaary space means map and its operation takes time logN
        vector<int> subarraySum(vector<int>arr, int n, long long s){
        unordered_map< int, int> m;
        long long sum = 0;
        for( int i=0; i<n; i++ ){
            sum += arr[i];
            if( sum==s ){
                return {1, i+1};
            }
            if( m.find(sum) == m.end() ){
                m[sum] = i+1;
            }
            if( m.find(sum-s) != m.end() ){
                return { m[sum-s]+1, i+1};
            }
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends

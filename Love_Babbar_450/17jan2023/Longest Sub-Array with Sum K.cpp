// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Same approach was used in subarray with sum 0 means if the curr Sum is existed earlier 
// Means we can take that subarray as a result
// Approach is simple we will store cummutative sum of each index if that sum is not pressent in map
// and we will check if curr sum - K is present in map means we can get that subarray by taking that whole subarray
class Solution{
    public:
        int lenOfLongSubarr(int A[],  int N, int K) {
        int ln=0;
        int sum=0;
        map<int,int>m;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==K)
                ln=max(i+1,ln);
            if( m.find(sum)==m.end() )//Simply pushing the cummutative sum of each indx in map if not present 
                m[sum]=i;
            if( m.find(sum-K)!=m.end() )
                ln = max(ln,i-m[sum-K]);
        }
        return ln;
    }

/* Aditya Verma Sliding Window Only for positives
    int lenOfLongSubarr(int arr[],  int N, int K) { 
        int sum = 0;
        int ans = 0;
        int i=0; 
        int j=0; 
        while( j<N ){
            sum += arr[j];
            if( sum==K ){
                ans = max( ans, j-i+1 );
                i++;
                j = i;
                sum = 0;
            }
            else if( sum>K ){
                i++;
                j = i;
                sum = 0;
            }
            else{
                j++;
            }
        }
        return ans;
    } 

*/
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
        priority_queue<ll> pq; // creating max heap
        ll sum = 0;
        for( ll i=0; i<N; i++ ){
            pq.push(A[i]);
        }
        while( pq.size() >=K2 ){
            pq.pop();
        }
        while( pq.size() >K1 ){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
    
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends

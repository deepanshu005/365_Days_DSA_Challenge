//CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if( n==1 )
            return 0;// beacuse the rope is already connected hence connecting cost will be zero

        priority_queue<long long, vector<long long>, greater<long long>>pq;
        for( int i=0; i<n; i++ )//for(auto x : arr)
            pq.push(arr[i]);
        
        long long cost=0;
        while( pq.size()>1 ){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();//getting two min lengths of ropes
            cost += (a+b);// cost of connecting two ropes is sum of their lengths
            pq.push(a+b);//pushing the length of new rope in priority queue
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

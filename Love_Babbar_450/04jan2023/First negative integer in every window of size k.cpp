// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//Test Cases Passed: 
//10055 /10100
//Time Limit Exceeded
typedef long long ll;
vector<ll> printFirstNegativeInteger(ll  A[],ll  N, ll  k) {
    queue<int> dq; 
    vector<ll> v;
    for(int i=0;i<k;i++){
        if( A[i]<0 )
            dq.push(A[i]);
    }
   
    if(dq.size()==0)
        v.push_back(0);
    else 
        v.push_back(dq.front());
   
    for( int i=k; i<N; i++ ){
        if(A[i-k]<0) 
            dq.pop();
        if(A[i]<0) 
            dq.push(A[i]);
       
        if(dq.size()==0 )
            v.push_back(0);
        else  
            v.push_back(dq.front());
    }
    return v;
}
/*

//Test Cases Passed: 
//10055 /10100
//Time Limit Exceeded
typedef long long ll;
vector<ll> printFirstNegativeInteger(ll  A[],ll  N, ll  K) {
    vector<ll> ans;
    
    for( ll i=0; i<=N-K; i++ ){
        ll j;
        for( j=i; j<K+i; j++ ){
            if(A[j]<0){
                ans.push_back(A[j]);
                break;
            }
        }
        if(j==K+i){
            ans.push_back(0);
        }
    }
    return ans;
}*/

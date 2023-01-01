// CPP DSA love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
// Simply following basics if we wanna all subarrays we will take two pointers for two nested loops starting from 0
// and all the subarrays will be within in these two pointers 
    int kthLargest(vector<int> &arr,int n,int K){
        priority_queue<int, vector<int>, greater<int>> pq;
        for( int i=0; i<n; i++ ){
            int sum = 0;
            for( int j=i; j<n; j++ ){// at each iteration we are discoveringa new subarray and pushing that sum in pq 
                sum += arr[j];
                pq.push(sum);
                if( pq.size()>K ){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends

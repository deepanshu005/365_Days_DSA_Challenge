// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        
        long sum = 0;
        long ans = -1;
    
        for( int i=0, j=0; j<N; j++ ){
            sum += Arr[j];    
            if( j-i+1 > K )//whenever size of window becomes greater than K hence subtracting first element 
                sum = sum - Arr[i++];
            
            ans = max(sum, ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends

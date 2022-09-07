// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxSum(int N){
        int j=1;
        int a[N];
        a[N-1]=(N+1)/2;
        for(int i=1; i<N-1; i+=2){
            if(j!=a[N-1]) a[i]=j;
            j++;
        }
        for(int i=-2; i<N-1; i+=2){
            if(j!=a[N-1]) a[i]=j;
            j++;
        }
        int sum = 0;
        for(int i=0; i<N-1; i++){
            sum += abs(a[i] - a[i+1]);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.maxSum(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

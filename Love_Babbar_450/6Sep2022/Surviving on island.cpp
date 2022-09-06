// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday = S/7; // this will give total sundays for S days
        int effec = S-sunday;// effec denotes the number of days on which we can buy food units
        int req = S*M;// Total food packets required to survive for S days
        
        int ans = ceil(req/(N*1.0));// this will give the min number of days we will be buying food to survive for S days
        if( ans>effec )// if numbers of days on which we buy food is greater than the total days, it means we can't survive
            return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends

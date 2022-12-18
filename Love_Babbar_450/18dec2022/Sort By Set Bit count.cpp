// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    // Set Bit means 1
    static int count(int N){ // Brian Kernighan’s Algorithm
        int Count = 0;
        while(N){
            int rsbm = N & -N;
            N = N-rsbm;
            Count++;
        }
        return Count;
    }
    static bool comp(int a, int b){
        int Ca = count(a);
        int Cb = count(b);
        return ( Ca > Cb );
    }
    // __builtin_popcount(x) returns the total number of 1's in x
    
    public:
    void sortBySetBitCount(int arr[], int n){
        stable_sort( arr, arr+n, comp );// maintains the relative order of same values
    }
    


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    int helper( int arr[], int start, int end, int k){
        if( start>end ){
            return -1;
        }
        int mid = start + (end-start)/2;// to prevent overflow of int
        if( arr[mid]==k )
            return mid;
        if( k > arr[mid] ){// if the array was reverse sorted the just chng the inequality if this if check baaki pura same
           return helper( arr, mid+1, end, k);
        }
        else{
            return helper( arr, start, mid-1, k);
        }
    }
  public:
    int binarysearch(int arr[], int n, int k) {
        // If the order is not known but mentioned only the array is sorted
        // bool isAsndng = arr[0]<arr[n-1];
        // then put conditions accordingly in if checks above
        return helper( arr, 0, n-1, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends

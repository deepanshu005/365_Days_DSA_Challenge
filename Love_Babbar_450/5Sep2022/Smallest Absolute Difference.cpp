// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


int kthDiff(int a[], int n, int k){
    
    vector<int> vec;
    int temp = 0;
    for( int i=0; i<n; i++ ){
        for( int j=i+1; j<n; j++ ){
            temp = abs( a[i] - a[j] );
            vec.push_back(temp);
        }
    }
    sort( vec.begin(), vec.end() );
    return vec[k-1];
}
// 10
// 5 7 9 3 4 2 1 8 9 10
// 10

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int arr[], int n) {
        int i = 0;
        int j = n-1;
        int mid = i + (j-i)/2;
        int res = -1;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( 1 == arr[mid]){
                j = mid-1;
                res = mid;
            }
            else if( 0==arr[mid] ){
                i = mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends

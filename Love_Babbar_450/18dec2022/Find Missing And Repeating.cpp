// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // long long sum = (n)*(n+1)/2;
        // long long newSum = 0;
        
        int *ans = new int[2];
        // for( int i=0; i<n; i++ ){
        //     newSum += arr[i];
        // }
        
        for( int i=0; i<n; i++ ){
            if( arr[abs(arr[i])-1] >  0 ){
                arr[ abs(arr[i])-1 ] *= (-1);
            }
            else{
                ans[0] = abs(arr[i]);
                
            }
        }
        for( int i=0; i<n; i++){
            if( arr[i]>0 ){
                ans[1] = i+1;
                break;
            }
        }
        // newSum = newSum-repeat;
        // int missing = sum-newSum;
        
        // ans[0] = repeat;
        // ans[1] = missing;
        return ans;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends

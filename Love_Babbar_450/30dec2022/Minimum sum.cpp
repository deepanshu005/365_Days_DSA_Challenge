// CPP DSA love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        string ans = "";
        sort( arr, arr+n );
        int i = n-1;
        int carry = 0;
        while( i>=0 ){
            int sum = 0;
            if( i==0 ){
                sum = arr[i] + carry;
            }
            else
                sum = arr[i]+arr[i-1]+carry;
                
            string val = to_string(sum%10);
            
            ans = val+ans;
            carry = sum/10;
            
            i-=2;
        }
        if( carry>0 ){
            
            ans = to_string(carry)+ans;
            
        }
        i = 0; 
        while(ans[i]=='0'){
            ans.erase(0,1);
        }
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// On left nikaalna h to left se traverse krna start kr do
// and right nikaalna h to right se traverse krna start kr do
    vector<int> leftSmaller(int n, int arr[]){
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        for( int i=0; i<n; i++ ){
            while( arr[i]<=st.top() ){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

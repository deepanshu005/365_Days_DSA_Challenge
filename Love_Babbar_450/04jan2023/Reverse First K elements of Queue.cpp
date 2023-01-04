// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    int size = q.size();
    stack<int> st;
    int n = 0;
    while( n++<k and !q.empty() ){
        st.push(q.front());
        q.pop();
    }
    int x = st.top();
    
    while( !st.empty() ){
        q.push(st.top());
        st.pop();
    }
    int i=0;
    while( i++<size-k ){
        q.push(q.front());
        q.pop();
    }
    return q;
}

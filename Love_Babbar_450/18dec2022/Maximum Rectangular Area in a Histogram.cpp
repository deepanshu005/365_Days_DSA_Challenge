// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<long long> prevSmallerElement(long long arr[], int n) {
        stack<long long> st;
        vector<long long>vec(n);
        st.push(-1);
        int i=0;
        while(i<n){
            int curr = arr[i];
            while( st.top() != -1 and arr[st.top()]>=curr ){
                st.pop();
            }
            vec[i] = st.top();
            st.push(i);
            i++;
        }
        return vec;
    } 
    
    
    vector<long long> nextSmallerElement( long long arr[], int n) {
        stack<long long> st;
        vector<long long>vec(n);
        st.push(-1);
        while(n--){
            int curr = arr[n];
            while( st.top() != -1 and arr[st.top()]>=curr ){
                st.pop();
            }
            vec[n] = st.top();
            st.push(n);
        }
        return vec;
    } 
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n){
        long long area = 0;
        
        vector<long long> next(n);
        next = nextSmallerElement(arr, n);
        
        vector<long long> prev(n);
        prev = prevSmallerElement(arr, n);
        
        for( int i=0; i<n; i++ ){
            long long l = arr[i];
            
            
            if( next[i]==-1 ){
                next[i] = n;
            }
            long long b = next[i]-prev[i]-1;
            long long newArea = l*b;
            area = max(newArea, area);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends

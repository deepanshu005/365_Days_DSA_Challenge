// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) { 
        stack<int> st;
        st.push(-1);
        vector<int> vec;
        while( n-- ){
            if( arr[n]>st.top() ){
                vec.push_back(st.top());
            }
            else{
                while( arr[n]<=st.top() ){
                    st.pop();
                }
                vec.push_back(st.top());
                
            }
            st.push(arr[n]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){

        vector<long long> ans(n);
        stack<long long> st;
        st.push(-1);  
        while(n--){
            long long curr=arr[n];
            while(!st.empty() && st.top()<=curr){
                st.pop();
          }
           // agar stack khali ho gya hai to -1 dal do
            if(st.empty())
                ans[n]=-1;
            // abb bada element mil gya hai
            else
                ans[n]=st.top();

            st.push(curr);
        }
        return ans;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

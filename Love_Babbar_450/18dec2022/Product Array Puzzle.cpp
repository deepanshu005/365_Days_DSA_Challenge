// CPP DSA Love babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> ans(n);
       long long int product = 1;
       int zero_index ;
       int count_zeroes = 0;
       for( int i=0; i<n; i++ ){
           if( nums[i]==0 ){
               zero_index = i;
               count_zeroes++;
               continue;
           }
           product = product*nums[i];
       }
       if( count_zeroes>1 ){
           return ans;
       }
       if( count_zeroes==1 ){
           ans[zero_index] = product;
           return ans;
       }
        for( int i=0; i<n; i++ ){
            ans[i] = product/nums[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

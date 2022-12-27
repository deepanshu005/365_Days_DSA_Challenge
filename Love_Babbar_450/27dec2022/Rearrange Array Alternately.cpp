// CPP DSA Love Babbar 450
//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    
    // naive approach if auxilliary space is allowed
    void rearrange(long long *arr, int n) {  
        vector<int>vec(n,0);
        for( int i=0; i<n; i++ ){
            vec[i] = arr[i];
        }
        int i = 0;
        int j = n-1;
        int k = 0;
        while( i<j ){
            arr[k++] = vec[j--];
            arr[k++] = vec[i++];
        }
        if( i==j ){
            arr[k] = vec[i];
        }
        return;
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends

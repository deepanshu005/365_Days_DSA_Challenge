//. CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size){
        if( size==1 ){
            return arr[0];
        }
        sort(arr, arr+size );
        int count = 0;
        int i;
        for( i=0; i<size-1; i++){
            if( arr[i]!=arr[i+1] ){
                count++;
                if( count>size/2 ){
                    return arr[i];
                }
                count = 0;
            }
            else{
                count++;    
            }
            
        }
        if( arr[i-1]==arr[i] ){
            count++;
        }
        if( count>size/2 ){
            return arr[i];
        }
       return -1; 
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends

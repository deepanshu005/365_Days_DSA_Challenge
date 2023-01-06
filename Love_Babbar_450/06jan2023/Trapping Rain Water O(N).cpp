// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    public:
    long long trappingWater(int arr[], int n){
    long long res = 0;
    int lMax = 0, rMax = 0, l = 0, r = n-1;
    while(l <= r) {
        if(arr[l] <= arr[r]) {
            if(arr[l] > lMax) 
                lMax = arr[l];
            else 
                res += lMax - arr[l];
            l++;
        } 
        else {
            if(arr[r] > rMax) 
                rMax = arr[r];
            else 
                res += rMax - arr[r];
            r--;
        }
    }
    return res;
}
    
    
    
    /*
        //Test Cases Passed: 
    //102 /152
    //Time Limit Exceeded
    // Naive approach
    public:
    int find( int arr[], int i, int j ){
        int ans = 0;
        for( int k=i; k<=j; k++ ){
            ans = max( ans, arr[k] );
        }
        return ans;
    }
    long long trappingWater(int arr[], int n){
        long long vol = 0;    
        long long temp = 0; 
        for( int i=0; i<n; i++ ){
            int maxL = find(arr, 0, i-1);
            int maxR = find(arr, i+1, n-1);
            temp = min(maxL,maxR)-arr[i];
            if( temp > 0 )
                vol += temp;
        }
        return vol;
    }*/
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends

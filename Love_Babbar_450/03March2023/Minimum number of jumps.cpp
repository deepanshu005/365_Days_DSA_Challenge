// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        // agar pahale hi point pr zero pada ho to bhaiya kaha jaoge. Ruk jao
        if(arr[0] == 0 && n>1) return -1;
        
        if(n == 1) return 0;
        
        // assume kro ki pahale point se apan jump lga diye hai
        int steps = arr[0];
        int maxReach = arr[0];
        int jumps = 1;
        
        for(int i = 1; i<n; i++){
            
            if(i == n-1) return jumps;
            
            // Ab apan agle point par aagye to maxReach nikalo aur store kralo
            if(steps) {
            	maxReach = max(maxReach, arr[i]+i);
            
            	// Ab apan agle point pr aagye hai to ek 			 step kam kardo
            	steps--;
            }
            
            // check kro ki steps khatm to nhi ho gye
            if(steps == 0){
                
                // agar end point tak pahuchne se pahale koi zero mil gya aur usse pahale koi maxReach nhi tha
                if(i>=maxReach) return -1;
                
                // steps khatm hue matlab new point par aagye
                // yha se bhi jump lga do
                // apan jump tabhi lagayenge jab steps khatm ho jayenge
                jumps++;
                
                // steps ko update krlo
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends

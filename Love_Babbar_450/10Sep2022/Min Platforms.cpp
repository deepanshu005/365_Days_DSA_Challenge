//CPP DSA Love Babbar 450
//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // we dont care which train comes or goes, the thing which matters to us is "Is platform vacant or not"
    int findPlatform(int arr[], int dep[], int n){
        sort(arr, arr+n);
        sort(dep, dep+n);
        int i=0, j=0;
        int ans=0;//stores the max platforms to be used as of now
        int now=0;// stores the total number of platforms using at any instant
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                i++;//since the train has arrived
                now++;//as new train has arrived hence it will need one more platform
            }
            else {
                j++;//since the train has departed
                now--;//as train has departed, hence one of the platform got vacant 
            }
            if( now>ans )
                ans = now;
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends

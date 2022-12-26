// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if( n==1 )
            return 0;
        if( arr[0]==0 )
            return -1;
        int maxi = arr[0];// stores the max reachable point for that particular index
        int steps = arr[0];
        int jump = 1;// coz we have already taken one jump
        for( int i=1; i<n; i++ ){
            if( i==n-1 ){// means we have reached to last 
                return jump;
            }
            maxi = max( maxi, i+arr[i] ); // 
            steps--;
            if( steps==0 ){
                jump++;
                if( i>=maxi ){
                    return -1;
                }
                steps = maxi-i;
            }
        }
    }
};
/* Naive Approach but TLE
    int minJumps(int arr[], int n){
        if( arr[0]==0 and n>0 )
            return -1;
        int jump = 0;
        int count = 0;
        for( int i=0; i<n; ){
            if( i+arr[i]>=n-1 ){
                return count+1;
            }
            jump = 0;
            int k = arr[i];
            int a = i+1;
            int index;
            while( a<=k+i ){
                if( arr[a]>jump ){
                    jump = arr[a];
                    index = a;
                }
                a++;
            }
            i = index;
            count++;
        }
        return count;
    }
    */


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

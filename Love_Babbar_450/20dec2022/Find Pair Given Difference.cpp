// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends
    int BS( int arr[], int i, int j, int y ){
        int mid;
        while( i<=j ){
            mid = i+(j-i)/2;
            if( arr[mid]==y )
                return mid;
            
            if( arr[mid]<y )
                return BS( arr, mid+1, j, y );

            else
                return BS( arr, i, mid-1, y );
        }
        return -1;
    }
bool findPair(int arr[], int n, int x){
    sort( arr, arr+n );
    for( int i=0; i<n; i++ ){
        
        if( arr[n-1]-arr[i] < x ){
            return false;
        }
        int y = arr[i]+x;
        int z = BS( arr, i+1, n-1, y );
        if( z!=-1 ){
            return true;
        }
    }
    return false;
}

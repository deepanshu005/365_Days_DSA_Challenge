// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int Bs(int arr[], int start ,int end, int k, char ch ){
    int res = -1;
    while( end >= start ){
        
        int mid = start + (end-start)/2;
        if( arr[mid] == k ){
            if( ch == 'l' ){
                res = mid; 
                end = mid-1;  
            }
            else if( ch == 'r' ){
                res = mid;
                start = mid+1;
            }
        }
        else if( k < arr[mid] ){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;
}


vector<int> find(int arr[], int n , int x ){
    vector<int>ans(2, -1);
    ans[0] = Bs( arr, 0 , n-1, x, 'l' );
    ans[1] = Bs( arr, 0 , n-1, x, 'r' );
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends

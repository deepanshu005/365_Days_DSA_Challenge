// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x){
        int i=0;
        int j=0;
        int sum = 0;
        int winSize = INT_MAX;
        while( i<=j and j<n ){
            while( sum<=x and j<n ){// jb tk sum chota h, j ko aage move krte jao
                sum += arr[j];
                j++;    
            }
            while( sum>x and i<j ){
                sum -= arr[i];
                winSize = min( winSize, j-i );
                //cout<<"Deepanshu"<<endl;
                i++;
            }
        }
        return winSize;
    }
    /*int sum = 0;
        int winSize = 0;
        for( int i=0; i<n; i++ ){
            if( sum>x )
                break;
            sum += arr[i];
            winSize++;
        }
        for( int i=0; i<=n-winSize; i++ ){
            if( sum>x ){// trying to reduce window size
                sum = sum-arr[i];
                winSize--;
            }
        }
        */
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends

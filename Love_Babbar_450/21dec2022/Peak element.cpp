// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution{
    // peak bole to apne neighbours k baraabar ya bda hoga
    int BS( int arr[], int i, int j, int n){
        int mid = i + (j-i)/2;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( (mid>0) and (mid<(n-1)) ){
                if( (arr[mid]>=arr[mid-1]) and (arr[mid]>=arr[mid+1]) ){
                    return mid;
                }
                else if( arr[mid]>arr[mid-1] ){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }
            else{
                if(mid==0 ){
                    if( arr[mid] > arr[mid+1] ){
                        return mid;    
                    }
                    return mid+1;
                }
                else if( mid==(n-1) ){
                    if( arr[mid] > arr[mid-1] ){
                        return mid;
                    }
                    return mid-1;
                }
            }
        }
        
    } 
   public:
    int peakElement(int arr[], int n){
        if(n==1)
            return 0;
        return BS( arr, 0, n-1, n ); 
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends

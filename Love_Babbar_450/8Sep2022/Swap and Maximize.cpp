// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n){
     sort(arr,arr+n);
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            ans+=abs(arr[j]-arr[i]);
            ans+=abs(arr[j]-arr[i+1]);
            i++;
            j--;
        }
        if(n%2==0)  j++;
        ans+=abs(arr[j]-arr[0]);
       return ans; 
}

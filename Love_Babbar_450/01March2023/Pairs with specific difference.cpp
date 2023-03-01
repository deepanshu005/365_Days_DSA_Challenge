// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
     int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        if(N==1){
            return 0;
        }
        sort(arr,arr+N);
        vector<int> left(N+2,0),right(N+2,0);
        right[N-1] = 0;
        if(arr[N-1]-arr[N-2]<K){
            left[N-1] = arr[N-1] + arr[N-2];
        }
        
       
        for(int i=N-2;i>=0;i--){
           if(arr[i+1]-arr[i]<K){
               right[i] =  arr[i] + arr[i+1] + max(right[i+2],left[i+3]);
               right[i] = max(right[i],right[i+1]);
            
            }else{
                right[i] = right[i+1];
            }
            if(i-1 >=0 && arr[i]-arr[i-1]<K){
                left[i] = arr[i] + arr[i-1] + max(right[i+1],left[i+2]);
                left[i] = max(left[i],left[i+1]);
            }else{
                left[i] = left[i+1];
            }
            // cout << left[i] << " " << right[i] << endl;
        }
        return max(left[0],right[0]);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends

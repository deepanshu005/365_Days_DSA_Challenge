// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    // Approach Using heap 
    vector <int> nearlySorted(int arr[], int n, int K){
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> vec;
        for( int i=0; i<n; i++ ){
            pq.push(arr[i]);
            if( pq.size()>K ){
                vec.push_back(pq.top() );
                pq.pop();
            }
        }
        while( !pq.empty() ){
            vec.push_back(pq.top() );
            pq.pop();
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends

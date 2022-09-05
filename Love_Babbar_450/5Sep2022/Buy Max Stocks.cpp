// CPP DSA Love Babbar 450
//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> vec;
        for( int i=0; i<n; i++ ){
            vec.push_back( make_pair(price[i], i+1 ));
        }
        sort( vec.begin(), vec.end() );//Inbuilt sort fxn wil sort the vector basis on first of pair that is price of stocks
        int count = 0;
        int i = 0;// for traversing the vector
        int m = vec.size();
        while( k>0 && i<m ){
            count = count +  min(vec[i].second, k / vec[i].first);
            k = k-vec[i].first * min(vec[i].second,(k / vec[i].first));
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends

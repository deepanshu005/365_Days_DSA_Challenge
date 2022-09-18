// CPP DSA Love Babbar 450
//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort( X.begin(), X.end(), greater<int>() );// Arranging vector in descending order
        sort( Y.begin(), Y.end(), greater<int>() );// Arranging vector in descending order
        int hori = 1;
        int vert = 1;
        int i=0;// to traverse on X
        int j=0;// To traverse on Y
        int cost = 0;
        while( i<M-1 and j<N-1 ){//Since length is M hence number of cits required will be M-1 for M peices
            if( X[i]>Y[j] ){// means vertical cut
                hori++;//coz after each vertical cut there will be increament in horixontal pieces
                cost += vert*X[i];
                i++;
            }
            else{
                vert++;//coz after each vertical cut there will be increament in horixontal pieces
                cost += hori*Y[j];
                j++;
            }
        }
        while( i<M-1 )
            cost += vert*X[i++];
        
        while( j<N-1 )
            cost += hori*Y[j++];
        
        return cost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends

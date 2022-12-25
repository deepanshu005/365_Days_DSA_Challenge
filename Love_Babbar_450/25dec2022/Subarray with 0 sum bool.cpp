// CPP DSA Love Babbar 450
//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    //Approach is simple cumuttative count of each term ek map mein store krenge
    // and jb kbhi bhi curr count kissi bhi prev count se match hoga means there exists an subArray which sums zero
    //and aise koi bhi term k liye nukaala jaa skta h not only for zero
    // and ek question wo bhi tha jisme hum count krte h number of subArrays
    /* for( int i=0; i<n; i++ ){ // counting number of subArrays
            sum += arr[i];
            
            if( myMap[sum]>=1 ){
                count += myMap[sum];
            }
            myMap[sum]++;
        }
        */
    bool subArrayExists(int arr[], int n){
        map< int,int >myMap;
        int curr = 0;
        myMap[0] = 1;
        for( int i=0; i<n; i++ ){
            curr += arr[i];
            if( myMap[curr] ){
                return true;
            }
            myMap[curr]++;
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends

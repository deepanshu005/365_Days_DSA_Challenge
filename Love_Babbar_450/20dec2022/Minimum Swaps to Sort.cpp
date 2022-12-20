// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    // Approach
    // Basically hum original vector ko phle map mein store kr lenge with the corresponding index of each element
    // then vector ko sort kr denge
    // ab count krenge swaps required to convert that sorted into original
	int minSwaps(vector<int>&nums){
	    map<int, int> myMap;
	    int n = nums.size();
	    int i=0;
	    int count=0;
	    for( auto x : nums ){
	        myMap[x] = i;
	        i++;
	    }
	    sort( nums.begin(), nums.end() );
	    for( int i=0; i<n; i++ ){
	        int index = myMap[nums[i]];
	        if( index !=i ){
	            swap( nums[index], nums[i] );
	            count++;
	            i--;
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

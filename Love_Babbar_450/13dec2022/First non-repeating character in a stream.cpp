// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> count(26,0);
		    vector<char> uni;
		    string ans = "";
		    int n = A.length();
		    for( int i=0; i<n; i++ ){
		        count[ A[i]-'a' ]++;
		        if( count[ A[i]-'a' ] == 1 )
		            uni.push_back( A[i] );
		        int k = uni.size();
		        bool flag = false;
		        for( int j=0; j<k; j++ ){// finding the first unique element in the uni vector
		            if( count[uni[j]-'a'] == 1 ){
		                ans.push_back( uni[j] );
		                flag = true;
		                break;
		            }
		        }
		        if(!flag)
		            ans.push_back('#');
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{//Previous code was not running because of duplicacy in given string hence we will be using set instead of vector to store result such that no duplicacy will be there
    private:
        void helper( string str, set<string> &ans, int start, int n ){
            if( start>=n ){    // Base case
                ans.insert(str);
                return;
            }
            for( int i=start; i<n; i++ ){
                swap( str[start], str[i] );//small calculation
                helper( str, ans, start+1, n );//recursive 
                swap( str[start], str[i] );
            }
    
        }
	public:
	    //If length of string is n then total permutations will bw n!
		vector<string>find_permutation(string str){
		    //if length of string is n then n! will be permutations of the given string
            set<string>ans;
            vector<string> result;
            int n = str.length();
            helper( str, ans, 0, n );
            result.assign(ans.begin(), ans.end() );
            sort(result.begin(),result.end() );
            return result;
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends

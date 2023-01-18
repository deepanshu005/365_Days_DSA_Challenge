// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// Aaditya Verma's Approach
// Simply taking a frequency map 
// Whenever number of unique chars hit the value K we will capture that result
// And if it goes more than required we will remove them form right index i
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> mp;
        int ans = -1;
        int i=0;
        int j=0;
        int n = s.length();
        while( j<n ){
            mp[s[j]]++;

            if( mp.size()==k ){// No. of unique chars hit the required value
                ans = max( ans, j-i+1 );
            }
            
            while( mp.size()>k and i<j ){// removing chars from right side 
                mp[s[i]]--;
                if( mp[s[i]]==0 )
                    mp.erase( s[i] );
                i++;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends

// CPP DSA LOve Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S){
    unordered_map<char,int> mp;
    int count = 0;// counts the number of simillar chars in current window
    int ans = 1;
    int n = S.size();
    int i = 0;
    int j = 0;
    while( j<n ){
        mp[S[j]]++;
        if( mp[S[j]]>1 ){
            count++;
        }
        if( count==0 ){
            ans = max( ans, j-i+1 );
        }
        while( count>0 and i<j ){
            mp[S[i]]--;
            if( mp[S[i]]==1 ){
                count--;
            }
            i++;
        }
        j++;
    }
    return ans;
}

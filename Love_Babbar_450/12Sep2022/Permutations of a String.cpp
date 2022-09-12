//CPP DSA Love Babbar 450
#include<bits/stdc++.h>
void helper( string str, vector<string> &ans, int start, int n ){
    if( start>=n ){    // Base case
        ans.push_back(str);
        return;
    }
    for( int i=start; i<n; i++ ){
        swap( str[start], str[i] );
        helper( str, ans, start+1, n );
        //Backtracking
        swap( str[start], str[i] );
    }
    
}
vector<string> generatePermutations(string &str){
    //if length of string is n then n! will be permutations of the given string
    vector<string> ans;
    int n = str.length();
    helper( str, ans, 0, n );
    sort( ans.begin(), ans.end());
    return ans;
}

// CPP DSA Love Babbar 450 
#include<bits/stdc++.h>
class Solution {
public:
    
    vector<string> letterCombinations(string str, vector<string> ans = {""} ) {
        string key[] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        int x = str[0] - 48;// converting  each character to corresponding integer
        
        if( ans[0] == str ) // special edge case if str is empty
            return {};
        if( str== "" && ans[0] != str ) // Base case for recursion 
            return ans;
        int k = key[x].size();
        int m = ans.size();
        int t = str.length();
        for( int i=1; i<k; i++ ){// making (k-1) copies of 
            for( int j=0; j<m ; j++ ){
                ans.push_back( ans[j] );// Means initialising new entries
            }
        }
        for( int i=0; i<k; i++ ){
            for( int j=0; j<m ; j++ ){
                ans[ m*i+j ] += key[x][i];//now updating all the strings in the vector ans by adding the newcharacter
            }
        }
        return letterCombinations(str.substr(1, t-1), ans);
    }
};

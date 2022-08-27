// CPP DSA Love Babbar 450
#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n){
    int m = arr[0].length();
    for( int i=0 ;i<n; i++ ){
        if( arr[i].length()<m )    
            m = arr[i].length();
    }
    string str = "";
    for( int i=0; i<m; i++ ){
        char ch = arr[0][i];
        for( int j=0; j<n; j++){
            if( arr[j][i] != ch ){
                return str;
            }
        }
        str += ch;
    }
    return str;
}



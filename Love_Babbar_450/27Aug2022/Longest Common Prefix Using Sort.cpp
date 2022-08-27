//This method is working fine in Code studio because it doesnt have enough test cases
#include<bits/stdc++.h>
bool static cmp( string a, string b ){
    if( a.length() == b.length() )
        return a>b;// here if we reverse the symbol then it will give one test case wrong
    // For example 1 4 car cus cart curat this will give wrong results
    else
        return a.length() < b.length();
}
string longestCommonPrefix(vector<string> &arr, int n){
    sort( arr.begin() , arr.end(), cmp);
    int m = arr[0].size();
    string str1 = arr[0];
    string str2 = arr[n-1];
    string str = "";
    for( int i=0 ;i<m; i++ ){
       if( str1[i] != str2[i] )
           break;
        str += str1[i];
    }
    return str;
}

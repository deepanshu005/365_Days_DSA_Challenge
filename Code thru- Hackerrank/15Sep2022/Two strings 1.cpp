#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int check( string a, string b){
    int n = min( a.length(), b.length());
    for( int i=0; i<n; i++ ){
        if( tolower(a[i])<tolower(b[i]) ){
            return -1;
        }
        else if( tolower(a[i])>tolower(b[i]) ){
            return 1;
        }
    }
    return 0;
}
int main() {
    string a;
    string b;
    cin>>a>>b;
    cout<<check( a, b );
    return 0 ;
}

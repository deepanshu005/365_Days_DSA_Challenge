#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    string a, b;
    int t;
    cin>>t;
    vector<string>vec;
    while( t>0 ){
        cin>>a>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n = a.length();
        bool equal = true;
        for( int i=0; i<n; i++){
            if( a[i]!=b[i] ){
                vec.push_back("sad");
                equal = false;
                break;
            }
            
        }
        if(equal)
                vec.push_back("happy");
        t--;
    }
    for( auto x : vec )
        cout<<x<<endl;
    return 0;
}

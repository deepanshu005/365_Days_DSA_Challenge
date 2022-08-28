//CPP DSA Love Babbar 450
#include<bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat) {
    vector<int> vec;
    int d = 256;
    int j;
    int q = INT_MAX;
    int M = str.length();
    int N = pat.length();
    int h = 1;
    for( int i=0; i<N-1; i++ ) 
        h = (h*d)%q;
    int S = 0;
    int P = 0;
    for( int i=0; i<N; i++ ){
        P = (P*d + pat[i])%q;
        S = (S*d + str[i])%q;
    }
    for( int i=0; i<=M-N; i++ ){
         if( P==S ){
            for( j=0; j<N; j++ ){
                if( str[i+j] != pat[j] )
                    break;
            }
            if( j==N )
                vec.push_back(i);
           }
        S = ( d*( S-str[i]*h ) + str[i+N] )%q;
        if( S<0 )
                S += q; 
    }
    return vec;
}


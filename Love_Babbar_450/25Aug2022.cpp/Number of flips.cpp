//Love babbar 450 DSA
#include<stack>
#include<bits/stdc++.h>
string DtoB( int a ){
    stack<int> st;
    string str = "";
    while( a!=1 ){
        st.push(a%2);
        a /= 2;
    }
    st.push(a);
    while( !st.empty() ){
        str += to_string(st.top());
        st.pop();
    }
    return str;
}
int numberOfFlips(int a, int b){
    string A = DtoB(a);
    string B = DtoB(b);
    int m = A.length();
    int n = B.length();
    if( m>n ){
        for( int i=1; i<=m-n; i++ )
            B = "0" + B;
    }
    if( m<n ){
        for( int i=1; i<=n-m; i++ )
            A = "0" + A;
    }
//     std::cout<<A<<endl<<B<<endl;
    int count = 0;
    n = B.length();
    for( int i=0; i<n; i++){
        if( A[i] != B[i] )
            count++;
    }
    return count;
}

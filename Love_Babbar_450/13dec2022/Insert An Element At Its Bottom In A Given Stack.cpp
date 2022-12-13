// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
void helper( stack<int>& st, int x ){
    if( st.empty() ){
        st.push(x);
        return;
    }
    else{
        int a = st.top();
        st.pop();
        helper( st, x);
        st.push(a);
    }
}
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    helper( myStack, x);
    return myStack;
}

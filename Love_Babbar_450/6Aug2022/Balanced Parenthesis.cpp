//CPP DSA CN Lec 10
#include<stack>
#include<cstring>
bool isBalanced( string str ) {
    stack <char> s;
    int n = str.length();
    for( int i=0; i<n; i++ ){
        if( str[i] == '(')
            s.push(str[i]);
        else if( !s.empty() && str[i] == ')' )	// Empty stack mein ye ')' kbhi bhi insert nhi hoga
            s.pop();
        else	// if stack is empty and we got ')' hence return false
            return false;
    }
	return s.empty();	// stack is empty only if parenthesis are balanced
    					// And if initially the stack was empty then it will be considered in balanced parenthesis
}

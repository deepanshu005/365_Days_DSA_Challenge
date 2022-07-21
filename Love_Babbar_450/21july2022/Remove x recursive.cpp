// Dsa Lecture 3 continued
#include<cstring>
// Change in the given string itself. So no need to return or print anything
void helper( char input[], int s, int k ){
    
    if( s==k )
        return;
    if( input[s]=='x' ){
        for( int i=s; i<=k+1; i++ )
			input[i] = input[i+1];
    }
    if( input[s]=='x')	//even after shifting one to the left there may be the case when there is x again at the same index after shifting 
        return helper( input, s, k );	//hence checking if x is there or not and amking recursive calls accordingly
    else
        return helper( input, s+1, k );	//if x is not there
}
void removeX(char input[]) {
    int k = strlen(input)-1;
    return helper( input, 0, k );	//Passing k to optimize TC coz it took time in calculating strlen again n again
}

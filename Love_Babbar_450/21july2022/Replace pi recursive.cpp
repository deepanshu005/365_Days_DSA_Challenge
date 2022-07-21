// Dsa Lecture 3 continued
// Change in the given string itself. So no need to return or print anything
#include<cstring>
void helper( char input[], int s ){
    int k = strlen(input) - 1;
    if( s==k )
        return;
    if( input[s]=='p' && input[s+1]=='i' ){
        for( int i=k+1; i>=s+2; i-- ){
            input[i+2] = input[i];	// Shifting two indexes right coz we have to insert 3.14 means four chars and remove p and i means two chars
        }
        input[s]='3';
        input[s+1]='.';
        input[s+2]='1';
        input[s+3]='4';
    }
    helper( input, s+1 );
}
void replacePi(char input[]) {
	helper( input, 0 );    
}







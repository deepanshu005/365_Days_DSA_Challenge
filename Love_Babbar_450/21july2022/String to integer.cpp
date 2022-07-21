// Dsa Lecture 3 continued
#include<cstring>
#include<cmath>
int stringToNumber(char input[]) {
    int k = strlen(input);
    if( k==1 )
        return input[0]-'0';	//Also instead of subtracting'0' we can subtract direct ascii value of zero
    int num = input[0]-48;	// Convertin char into integer by subtracting ascii value of 0 from that particular char
    return num*pow(10,k-1) + stringToNumber( input+1 );	// This is Tail recursion 
    
}



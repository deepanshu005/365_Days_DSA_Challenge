// Dsa Lecture 3 continued
//Previous submission is lil bit optimized
#include<cstring>
// Change in the given string itself. So no need to return or print the changed string.
void helper( char input[], int s){
    int k = strlen(input);
    if( s==k )
        return;
    if( input[s]==input[s+1] ){
        for( int i=k; i>s; i-- ){	//Shifting the whole string by one to right side
            input[i+1] = input[i];
        }
        input[s+1] = '*';	//Now putting '*' at the index next to s
    }
    return helper( input, s+1 );	// Actually there is no need of maintaing s bcoz we need only index zero and one as in previous submission
}
void pairStar(char input[]) {
    return helper( input, 0);

}

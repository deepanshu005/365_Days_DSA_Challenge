// Lecture 3 DSA coding ninjas
int power(int x, int n) {
	if( n==0 )	// Base case
        return 1;
    int output = power( x, n-1 );	// Recursive call 
    return output*x;	//Small calculation
}

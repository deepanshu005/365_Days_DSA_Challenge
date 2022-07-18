// DSA Lecture 3
// Ye code phle base case pe jaaega and then ek ek krke digits count krna shuru krega Most Significant digits se
int sumOfDigits(int n) {
	if( n==0 )
        return 0;
    int output = sumOfDigits( n/10 );	//Head recursion
    return output+(n%10);
}



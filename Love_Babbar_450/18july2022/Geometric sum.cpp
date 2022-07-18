// DSA Lecture 3 coding ninjas
#include<cmath>
double geometricSum(int k) {
	if( k==0 )
        return 1;
    double output = geometricSum( k-1 );	//This is head recursion hence first of all reach to the base case and then start small calculations
    return output+ 1/(pow(2,k));
}



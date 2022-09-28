//CPP DSA CN Lec 18 Love babbar 450
int helper( int *arr, int n ){
    if( n<=1 )
        return 0;
    if( arr[n]!=0 )
    	return arr[n];    
    int x = helper( arr, n-1 );
    int y = INT_MAX;
    int z = INT_MAX;
    if( n%2==0 )
        y = helper( arr, n/2 );
    if( n%3==0 )
        z = helper( arr, n/3 );
   
    arr[n] = min( x, min(y,z) )+1;
    return arr[n];
}
int countStepsToOne(int n)
{
	int *result = new int[n+1]();
    return helper( result, n );
}

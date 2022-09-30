// CPP DSA Cn Lec 18 Love Babbar 450
#include<cmath>
int balancedBTs(int n) {
    if( n<=1 )
        return 1;
    int mod = (int)(pow(10,9)) + 7;
    
    int x = balancedBTs( n-1 );
    int y = balancedBTs( n-2 );
    int temp1 = (int)( ((long)(x)*x)%mod );
    int temp2 = (int)( 2*((long)(x)*y)%mod );
    int ans = (temp1 + temp2)%mod;
    return ans;
}
//Below code is using memoization 
/*
#include<cmath>
const int N =1e6;
int arr[N] = {0};
int balancedBTs(int n) {
    int mod = (int)(pow(10,9)) + 7; //Also insted of pow(10,9) , 1e8 +7 can be used
    if( n<=1 )
        return 1;
	if( arr[n] != 0 )
        return arr[n];
    
    int x = balancedBTs( n-1 );
    int y = balancedBTs( n-2 );
    int temp1 = (int)( ((long)(x)*x)%mod );
    int temp2 = (int)( 2*((long)(x)*y)%mod );
    arr[n] = (temp1 + temp2)%mod;
    return arr[n];
}
*/

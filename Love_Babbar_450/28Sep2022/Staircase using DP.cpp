//CPP DSA CN Lec 18 Love Babbar 450
//This method is using memoization 
// Both are correct
#include<bits/stdc++.h>
long helper( long arr[], int n )
{    
    if( n == 0 )
        return 1;
    
    if(n== 1 || n == 2)
        return n;
    
    
    if( arr[n] != -1 )
        return arr[n];
    
    arr[n] = helper(arr,n-1) + helper(arr,n-2) + helper(arr,n-3);
    return arr[n];
}
long staircase(int n){
	long *arr = new long[n+1];
    for(long i = 0 ; i <= n;i++)
        arr[i] = -1;
    
    return helper(arr, n);
}
// This method is using DP
/*long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     
    long *arr = new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
    
}
*/

// CPP DSA CN Lec 18 Love Babbar 450
int minCount(int n){
    int *ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i=4;i<=n;i++){
        int small = INT_MAX;
        int j=1;
        while((j*j)<=i){
           int x = ans[i-(j*j)];
            small = min(x+1,small);
            j++;
        }
        ans[i]=small;
    }
    return ans[n];
}


/*// Also this method is correct
//This method is called memoization
int *arr = new int[10002];
int minCount(int n){
    if( sqrt(n) - floor(sqrt(n)) ==0 )
        return 1;
	if( n<=3 )
        return n;
    if( arr[n]!= 0 )
        return arr[n];
    int result = n;
    for(int i=1; i<=floor(sqrt(n)); i++ ){
        result = min(result, 1+minCount(n-i*i));
        arr[n] = result;
    }
    return arr[n];
}
*/

/*
//Although this method is correct but its Time complexity is order of exponential 
int minCount(int n)
{
    if( sqrt(n) - floor(sqrt(n)) ==0 )
        return 1;
	if( n<=3 )
        return n;
    int result = n;
    for(int i=1; i<=floor(sqrt(n)); i++ )
    	result = min( result, 1+minCount(n-i*i));
    
    return result;
}
*/

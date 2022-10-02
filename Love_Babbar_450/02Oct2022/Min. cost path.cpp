// CPP DSA CN Lec 19 Love Babbar 450
//Brute Force Approach
int minCostPath(int **input, int m, int n){
	
    if( m==1 && n==1 )
        return input[m-1][n-1];
    if( m<1 || n<1 )
        return INT_MAX;
    int x = minCostPath(input, m-1, n-1);
    int y = minCostPath(input, m-1, n);
    int z = minCostPath(input, m, n-1);
    int Min = min( x, min(y,z) )+input[m-1][n-1];
    return Min ;
}  
//Memoization
int minCostPath(int **input, int m, int n){
	
    if( m==1 && n==1 )
        return input[m-1][n-1];
    if( m<1 || n<1 )
        return INT_MAX;
    int x = minCostPath(input, m-1, n-1);
    int y = minCostPath(input, m-1, n);
    int z = minCostPath(input, m, n-1);
    int Min = min( x, min(y,z) )+input[m-1][n-1];
    return Min ;
}  

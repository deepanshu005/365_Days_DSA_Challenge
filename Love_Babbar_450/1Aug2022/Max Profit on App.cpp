// CPP DSA CN Test 1
// Return the max profit
// profit is price of app multiplied number of subscribers
/*
Approach is simple after sorting the whole array run a loop and assume each budget as the price of app and for each index i total subscribers will be (n-i) 
And therefore profit will be (n-i)*budegt[i] for each ith budget 
*/
#include<algorithm>
int maximumProfit(int budget[], int n) {
    sort( budget, budget+n );
	int MaxProfit = 0;
    int Profit = 0;
    for( int i=0; i<n; i++ ){
    	Profit = budget[i]*(n-i);
		if( Profit> MaxProfit )
			MaxProfit = Profit;
	}
    return MaxProfit;
}

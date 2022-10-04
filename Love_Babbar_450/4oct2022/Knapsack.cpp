//CPP DSA CN Lec 19 Love Babbar 450
#include <iostream>
using namespace std;

int knapsack(int *w, int *v, int n, int maxw)
{
	//write your code here
    if(n==0 || maxw<=0)
        return 0;
    
    if(w[0]>maxw)
        return knapsack(w+1,v+1,n-1,maxw);
    
    int x=knapsack(w+1,v+1,n-1,maxw-w[0])+v[0];
    int y=knapsack(w+1,v+1,n-1,maxw);
    return max(x,y);
}

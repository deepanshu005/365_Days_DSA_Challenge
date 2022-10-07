//CPP DSA CN Lec 19 Love Babbar 450
/*
//2nd approach

#include<cmath>
int apw(int num, int power, int n){
	if(num==0){
		return 1;
	}
	if(num < 0){
		return 0;
	}
	int reducer = pow(n, power);
	if(reducer > num){
		return 0;
	}
	int x = apw(num-reducer, power, n+1);
	int y = apw(num, power, n+1);
	return x+y;
}

int getAllWays(int a, int b) {
	// Write your code here
    return apw(a, b, 1);
}
*/
//1st approach

#include <iostream>
using namespace std;

int power(int num, unsigned int n) 
{ 
    if (n == 0) 
        return 1; 
    else if (n%2 == 0) 
        return power(num, n/2)*power(num, n/2); 
    else
        return num*power(num, n/2)*power(num, n/2);
}

int check(int x,int n,int curr_num,int curr_sum){
    int res=0;
    int p = power(curr_num,n);
    while(p+curr_sum<x){
        res += check(x,n,curr_num+1,curr_sum+p);
        curr_num++;
        p=power(curr_num,n);
    }
    if(p+curr_sum==x)
        res++;
    return res;
}

int getAllWays(int x, int n) {
    return check(x,n,1,0);
}

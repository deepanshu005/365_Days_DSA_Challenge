//CPP DSA CN Lec 19 Love Babbar 450
#include<iostream>
#include<string>
#include <vector>
using namespace std;

int BeerusWin(vector<int> &dp,int n,int x,int y){
    if(n==1 || n==x || n==y)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    
    int ans;
    //You'll have take care when n>x or <x, likewise for y
    if(n>x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y) || !BeerusWin(dp,n-y,x,y);
    else if(n>x && n<y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y);
    else if(n<x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-y,x,y);
    else
        ans=!BeerusWin(dp,n-1,x,y);
    
    dp[n]=ans;
    return dp[n];
}


string findWinner(int n, int x, int y)
{
	// Write your code here .
    vector<int> dp(n+1,-1);
    
    int ans=BeerusWin(dp,n,x,y);
    
    if(ans)
        return "Beerus";
    else
        return "Whis";
}

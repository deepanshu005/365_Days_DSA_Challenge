//CPP DSA CN Lec 19 Love Babbar 450
int count(int denom[],int **dp,int m,int n)
{
    
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(m==0)
    {
        return 0;
    }
    if(dp[n][m-1]!=-1)
    {
        return dp[n][m-1];
    }
    int a=count(denom+1,dp,m-1,n);
    int b=count(denom,dp,m,n-denom[0]);
    int ans=a+b;
    dp[n][m-1]=ans;
    return ans; 
}
int countWaysToMakeChange(int denom[], int m, int n){
  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1;
        }
    }
    //int i=0;
    //int j=0;
    int ans=count(denom,dp,m,n);
    for(int i=0;i<=n;i++)
    {
        delete dp[i];
    }
    delete []dp;
    return ans;
}

//CPP DSA CN Lec 19 Love Babbar 450
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
     int dp[maxWeight+1]={0};
    
    for(int i=0;i<n;i++){
        
        for(int j=maxWeight;j>=weights[i];j--){
            
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[maxWeight];


}

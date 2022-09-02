// CPP DSA CN Lec 15
#include<unordered_map>
/*int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> map;
    int Csum = 0;
    int maxlen=0;
    int i=0, j=0;
    for( int k=0; k<n; k++ ){
    	Csum += arr[i];
        map[Csum]++;
        if( (j-i)>maxlen ){
            maxlen= j-i;
            
        }
    }
}*/





int lengthOfLongestSubsetWithZeroSum(int* arr, int n) 
{
    // Write your code here
    unordered_map<int,int> mapp;
    mapp[0] = -1;
    int sum = 0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
       int temp=0;
       sum += arr[i];
       if(mapp.count(sum) > 0)
       {
           temp = i-mapp[sum];
           ans = max(temp,ans);
       }
       else
            mapp[sum] = i;
    }
    return ans;
}

// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    // subarray bole to continuous part of array
    // Subsequence bole to taking random elements of array
    int findLongestConseqSubseq(int arr[], int N){
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        while( i<N )
            pq.push(arr[i++]);
        
        int count = 1;
        int temp = 1;
        int prev = pq.top();
        while( !pq.empty() ){
            if( pq.top()==prev+1 ){
                temp++;
                count = max( temp, count);
                prev = pq.top();
                pq.pop();
            }
            else if( pq.top()==prev ){
                prev = pq.top();
                pq.pop();
            }
            else{
                temp = 1;
                prev = pq.top();
                pq.pop();
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends

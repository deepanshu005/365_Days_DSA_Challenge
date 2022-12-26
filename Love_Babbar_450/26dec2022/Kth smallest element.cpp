// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    // AS kth smallest is asked hence we use max heap
    // we keep on pushing elemnts to pq until its size greater than k
    // whwnever the size exceeds the k then the top most elment will be max of all
    // then poping that element and keep on pushing and poping 
    // at the end we will be having k elemnts in the heap ans the top most element will be max of all the k elemnts
    // and then return that op element
    int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int>pq;
       for( int i=l; i<=r; i++ ){
           pq.push(arr[i]);
           if( pq.size()>k ){
               pq.pop();
           }
       }
       return pq.top();
    }
    /* TC : O(NlogN)
       SC : O(1)
    int kthSmallest(int arr[], int l, int r, int k) {
    // Basically sort krke k-1 index wala number return kr do
        sort( arr, arr+r+1 );
        return arr[k-1];
    }
    */
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends

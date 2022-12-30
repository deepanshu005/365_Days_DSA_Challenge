// CPP DSA Love Babbar 450
//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i){ // max heap
        int parent = i;
        int lc = 2*i+1;
        int rc = 2*i+2;
        
        if( lc<n and arr[parent]<arr[lc] ){
            parent = lc;
        }
        if( rc<n and arr[parent]<arr[rc] ){
            parent = rc;
        }
        if( parent != i ){
            swap( arr[parent], arr[i] );
            heapify( arr, n, parent );
        }
        return;
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) {
        //(n/2-1)th node is first non-leaf node i.e. all node greater than (n/2-1) are leaf node
        //so there is no need to heapified leaf node it get there desire position by parents
        //lower nodes get heapified first
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        //first we have to build max heap so we got max elm on top swap it to last
        //and iterate for length-1 array
        buildHeap(arr,n);
        //here we got max elm on idx 0 to swap it to last elm and we can clearly see after
        //swapping the 0th elm is only which is un heapified so heapify it i.e. take that elm 
        //to its pos.
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            //reduce array size by one in each iteration
            heapify(arr,i,0);    //since 0th elm is not heapified
        }
        
    }
};



//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends

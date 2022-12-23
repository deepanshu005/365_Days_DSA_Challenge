// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
   public:
    void merge(int *arr, int i, int m, int j){
        int len1 = m-i+1;
        int len2 = j-m;
        int *first = new int[len1];
        int *second = new int[len2];
        
        int k = i;
        for( int a=0; a<len1; a++ ){
            first[a] = arr[k++];
        }
        for( int a=0; a<len2; a++ ){
            second[a] = arr[k++];
        }
        int a = 0;
        int b = 0;
        k = i;
        while( a<len1 and b<len2 ){
            if( first[a]<second[b] ){
                arr[k++] = first[a++];
            }
            else{
                arr[k++] = second[b++];
            }
        }
        while( a<len1 ){
            arr[k++] = first[a++];
        }
        while( b<len2 ){
            arr[k++] = second[b++];
        }
    }
   public:
    void mergeSort(int arr[], int i, int j){
        if( j<=i ){
            return;
        }
        int mid = i + (j-i)/2;
        mergeSort( arr, i, mid );
        mergeSort( arr, mid+1, j );
        merge( arr, i, mid, j );
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends

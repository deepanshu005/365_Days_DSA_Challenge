// CPP DSA Love Babbar 450
//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

// this approach is exactly same as of median of a sorted matrix with slight change in if check of kthSmallest fxn
// fxn to count number of elments exactly less than equal to x
// its just a simple modification of finding the ceil of a given element
    int BS_ceil( int arr[], int i, int j, int x ){
        int mid = i + (j-i)/2;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( arr[mid]<=x ){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return i;// returns the total number of elements less than equal to x in curr row
    }


    int kthSmallest(int matrix[MAX][MAX], int n, int k){
        // first of all we need to know the search space to apply Binary search
        int i = mat[0][0];// this is the min element in the given matrix
        int j = mat[n-1][n-1];// this is the max element in the given matrix
        while( i<=j ){// lets shrink the search space
            int mid = i + (j-i)/2;
            int count = 0;// count bole to number of elements in matrix less than equal to mid
            for( int i=0; i<n; i++ ){
                count += BS_ceil(matrix[i], 0, n-1, mid );
            }
            if( count< k ){// km hua to humme right mein jaana pdega
                i = mid+1;
            }
            else{// count jyaada hoga to hume left mein jaana pdega
                j = mid-1;
            }
        }
        return i;
    }


// Approach is we first look for search space   
// and apply binary search on that search space each time 
//when we calculate mid element of search space we will look for total number of elements
// in the matrix which are less than or equal to the mid and this can be counted row wise 
// by applying BInary search on each row



/*
mat[][] =         {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}

// TC : O((N^2)logK)
// SC : O(K)
int kthSmallest(int mat[MAX][MAX], int n, int k){
    priority_queue<int> pq;// creating max heap
    for( int i=0; i<n; i++ ){
        for( int j=0; j<n; j++ ){
            pq.push( mat[i][j] );
            if( pq.size()>k ){
                pq.pop();
            }
        }
    }
    return pq.top();
}
*/


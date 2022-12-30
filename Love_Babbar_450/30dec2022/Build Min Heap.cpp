// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 

void heapify( vector<int> &arr, int n, int i ){
    int parent = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if( left<n and arr[left]<arr[parent] )
        parent = left;
    if( right<n and arr[right]<arr[parent] )
        parent = right;
    
    if( parent!=i ){// mtlb kush gdbd h ya to left chlld chota h ya fir right child bda h
        swap( arr[parent], arr[i] );
        heapify( arr, n, parent);
    }
}

vector<int> buildMinHeap(vector<int> &arr){
    // Since leaf nodes are already heapified hence we will only heapify the parent nodes
    // the parent node of last node i.e (n-1)th will be ((n-1)-1)/2 = (n/2) - 1
    int n = arr.size();
    for( int i = (n/2)-1; i>=0; i-- ){
        heapify( arr, n, i );
    }
    return arr;
}

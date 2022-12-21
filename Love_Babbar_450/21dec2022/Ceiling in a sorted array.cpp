// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
int BS_ceil( vector<int>arr, int i, int j, int x ){
    int mid = i + (j-i)/2;
    int index = -1;
    while( i<=j ){
        mid = i + (j-i)/2;
        if( arr[mid]==x ){
            return mid;
        }
        else if( x > arr[mid] ){
            i = mid+1;
        }
        else if( x < arr[mid] ){// Socho kya mid element ceiling ho skta h x ka 
            j = mid-1;
            index = mid;// yeas ho skta h hence store that ceil in index
        }
    }
    return index;
}

int ceilingInSortedArray(int n, int x, vector<int> &arr){
    int ans = BS_ceil(arr, 0, n-1, x);
    if( ans==-1 )
        return -1;
    return arr[ans];
}

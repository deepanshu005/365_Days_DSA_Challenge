// CPP DSA Love Babbar 450
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BS( int *arr, int i, int j, int target ){
    int mid = i + {j-i)/2;
    while( i<=j ){
        mid = i + (j-i)/2;
        if( arr[mid]==target ){
            return mid;
        }
        if( target<arr[mid] ){
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int arr[];
    for( int i=0; i<n; i++ ){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int i=0;
    int j=1;
    while( arr[j] < target ){
        i=j;
        j*=2;
    }
    int index = BS( arr, i, j, target);
    if( index!=-1 )
        return arr[index];
    return index;
}

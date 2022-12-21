// CPP DSA Love Babbar 450
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int BS( int arr[], int i, int j, int x){
    int prev;
    int next;
    int mid = i + (j-i)/2;
    while( i<=j ){
        prev = mid-1;
        next = mid+1;
        mid = i+(j-i)/2;
        if( arr[mid]==x ){
            return mid;
        }
        else if( mid>i and arr[prev]==x ){
            return prev;
        }
        else if( mid<j and arr[next]==x ){
            return next;
        }
        if( arr[mid]<x ){
            i = mid+2;
        }
        else
            j = mid-2;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for( int i=0; i<n; i++ ){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int index = BS(arr, 0, n-1, key );
    if( index==-1 )
        cout<<"not present";
    else
        cout<<index;
    return 0;
}

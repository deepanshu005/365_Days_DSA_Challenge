// CPP DSA Love Babbar 450
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int binarySearchMinDifference( int a[], int n, int target){
        
        if(target < a[0])
            return a[0];
        if(target > a[n - 1])
            return a[n - 1];

        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if(target == a[mid]) {
                return a[mid];
            } 
            else if(target < a[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        /*
           At the end of the while loop, 
           a[start] is the ceiling of target (Smallest number greater than target), and 
           a[end] is the floor of target (Largest number smaller than target).
           
           Return the element whose difference with target is smaller
         */
        if ((a[start] - target) < (target - a[end]))
            return a[start];
        return a[end];
    }


int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int target;
    cin>>target;
    return binarySearchMinDifference( arr, 8, target);
}

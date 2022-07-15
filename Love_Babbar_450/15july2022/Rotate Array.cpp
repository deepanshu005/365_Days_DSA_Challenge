#include<iostream>
using namespace std;
void rotate(int *input, int d, int n){
    int i;
    int temp[d];
    for(i=0;i<d;i++)//storing the first d elements in a temp array
        temp[i]=input[i];
    
    for(i=0;i<n-d;i++)// Shifting elements from index d to index 0      
        input[i]=input[i+d];
    
    for(i=0;i<d;i++)//Inserting  remaining d elements to the input array
        input[i+n-d]=temp[i];
}
int main() {
    int n; // Size of array
    cin >> n;
    int arr[n];
    //initializing array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k; // No. of times to rotate
    cin >> k;
    rotate(arr, k, n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}

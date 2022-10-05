// CPP DSA CN Lec 19 Love Babbar 450
#include<bits/stdc++.h>
using namespace std;
int maxMoneyLooted(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    int *output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        output[i]=max(arr[i]+output[i-2],output[i-1]);
    }
    return output[n-1];

}

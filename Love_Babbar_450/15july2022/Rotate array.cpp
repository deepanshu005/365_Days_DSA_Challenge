#include <iostream>
using namespace std;
void reverse( int *arr, int i, int j ){
    while(i<j){
        swap(arr[i++], arr[j--]);
    }
}
int main() {
    int N;
    cin>>N;
    int *arr = new int[N];
    for( int i=0; i<N; i++ )
        cin>>arr[i];
    int k;
    cin>>k;
    reverse( arr, 0, N-1 );
    reverse( arr, 0, N-k-1);
    reverse( arr, N-k, N-1);
    for( int i=0; i<N; i++ )
        cout<<arr[i]<<" ";
    return 0;
}
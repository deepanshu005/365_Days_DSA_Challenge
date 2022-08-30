//CPP DSA CN Lec 14
bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i = 1; i < n; i++){

        int parentIndex = (i- 1) / 2;
        if(arr[i] > arr[parentIndex]){

            return false;
        }
    }
    return true;
}

/*
bool isMax(int LC, int P, int RC){
    if( P>LC && P>RC)		return true;
    else false;
}
bool isMaxHeap(int arr[], int n) {
    for(int i=0; i<n; i++){
        if( arr[2*i+2]==NULL || arr[2*i+1]==NULL ) // Its not true coz 2*i+2 doesnt exist for i= n-1;
            continue;
        if(!isMax( arr[2*i+1], arr[i], arr[2*i+2] ))		return false;
    }
    return true;
}
*/

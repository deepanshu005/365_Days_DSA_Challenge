vector<int> separateNegativeAndPositive(vector<int> &arr){
    int i = 0;
    int j = arr.size()-1;
    while( i<j ){
        if(arr[i]>0 && arr[j]<0 )
            swap(arr[i++], arr[j--] );
        if(arr[i]<=0)
            i++;
        if(arr[j]>=0)
            j--;
    }
    return arr;
}
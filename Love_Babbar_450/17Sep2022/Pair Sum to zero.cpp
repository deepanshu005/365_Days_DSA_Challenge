// CPP DSA Love babbar 450
#include <unordered_map>

int pairSum(int *arr, int n){
    unordered_map<int,int>map;
    int c=0;
    for(int i=0;i<n;i++){
        if(map[-arr[i]]>0){
            c=c+map[-arr[i]];
        }
        map[arr[i]]++;
    }
    return c;
}


/*#include<unordered_map>
int pairSum(int *arr, int n) {
	unordered_map<int, int> sum;
    for( int i=0; i<n; i++ ){
        sum[arr[i]]++;
    }
    int Tpair = 0;
    for( int i=0; i<n; i++ ){
        if( sum.count(arr[i])>0 && sum.count(-arr[i])>0 ){
        Tpair += (sum[arr[i]] * sum[-arr[i]]);
        sum[arr[i]] = 0;
        sum[-arr[i]] = 0;
        }
    }
    return Tpair;
}*/

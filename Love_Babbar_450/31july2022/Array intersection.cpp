// CPP DSA CN Lec-5
#include<algorithm>
void intersection(int *arr1, int *arr2, int n, int m){
    sort( arr1, arr1+n );	
    sort( arr2, arr2+m );
    for( int i=0, j=0; i<n && j<m; ){
        if( arr1[i]==arr2[j] ){	// If both the elements are same then we are printing that element and incrementing both i and j
			cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else{
            if( arr1[i]<arr2[j] )	// If both elements are not equal then we are incrementing the index with lower value
				i++;
        	else
                j++;
        }
    }
}

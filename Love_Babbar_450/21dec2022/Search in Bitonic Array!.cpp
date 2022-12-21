// CPP DSA Love Babbar 450
int  BsIncr( vector<int> arr, int i, int j, int x,char ch ){
    int mid = i + (j-i)/2;
    while( i<=j ){
        mid = i + (j-i)/2;
        if( arr[mid]==x ){
            return mid;
        }
        if( ch=='I' ){// for increasing
            if( arr[mid]<x )
                i = mid+1;
            else
                j = mid-1;
        }
        if( ch=='D' ){// for decreasing
            if( arr[mid]>x )
                i = mid+1;
            else
                j = mid-1;
        }
    }
    return -1;
}
    int peak( vector<int> arr, int i, int j, int n){
        int mid = i + (j-i)/2;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( (mid>0) and (mid<(n-1)) ){
                if( (arr[mid]>=arr[mid-1]) and (arr[mid]>=arr[mid+1]) ){
                    return mid;
                }
                else if( arr[mid]>arr[mid-1] ){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }
            else{
                if(mid==0 ){
                    if( arr[mid] > arr[mid+1] ){
                        return mid;    
                    }
                    return mid+1;
                }
                else if( mid==(n-1) ){
                    if( arr[mid] > arr[mid-1] ){
                        return mid;
                    }
                    return mid-1;
                }
            }
        }
        
    } 
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int pivot = peak( A, 0, n-1, n );
    if( A[pivot]==B )
        return pivot;
    char ch = 'I';// I for increasing
    int index = BsIncr( A, 0, pivot, B, ch );
    if( index!=-1 )
        return index;
    ch = 'D';// D for decreasing
    index = BsIncr( A, pivot+1, n-1, B, ch );
    if( index!=-1 )
        return index;
    return -1;
      
}

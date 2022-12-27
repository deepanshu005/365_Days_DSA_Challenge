// CPP DSA Love Babbar 450
class Solution {
public:
    void reverse( vector<int>& arr, int i, int j ){
        while( i<j )
            swap( arr[i++], arr[j--] );
    }
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int idx = -1;

        for( int i=n-1; i>0; i-- ){
            if( arr[i]>arr[i-1] ){
                idx = i;// this is the element which is less
                break;
            }
        }
        if( idx==-1 ){
            reverse( arr, 0, n-1 );
            return;
        }
        int prev = idx;
        // to traverse the right part
        for( int i=idx+1; i<n; i++ ){// aisa element dhoondo jo idx se just greater ho
            if( arr[i]<=arr[prev] and arr[i]>arr[idx-1] )
                prev = i;
            
        }
        swap( arr[idx-1], arr[prev] );
        reverse( arr, idx, n-1 );

        return ;
    }
};

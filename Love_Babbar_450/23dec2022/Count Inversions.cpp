// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long i, long m, long j, long &ans ){
        long len1 = m-i+1;
        long len2 = j-m;
        long *first = new long[len1];
        long *second = new long[len2];
        
        int k = i;
        for( int a=0; a<len1; a++ ){
            first[a] = arr[k++];
        }
        for( int a=0; a<len2; a++ ){
            second[a] = arr[k++];
        }
        int a = 0;
        int b = 0;
        k = i;
        while( a<len1 and b<len2 ){
            if( first[a]<=second[b] ){
                arr[k++] = first[a++];
            }
            else{
                arr[k++] = second[b++];
                ans += (len1-a);// mtlb humaare paas do subaarrays h first and second and both are sorted in ascending , humaare paas jb kbhi bhi 
            }//first k ander koi element second se chota aayega to wo inversion mein +1 contribute krega and uske right side mein jitne bhi elements honge wo saare contribute krenge 
        }// ab wo bche hue elements hain kitne wo honge ( length of first )- current position of element here it is a
        while( a<len1 ){
            arr[k++] = first[a++];
        }
        while( b<len2 ){
            arr[k++] = second[b++];
        }
        delete [] first;
        delete [] second;
    }
    void mergeSort(long long arr[], long i, long j, long &ans ){
        if( j<=i ){
            return;
        }
        int mid = i + (j-i)/2;
        mergeSort( arr, i, mid, ans );
        mergeSort( arr, mid+1, j, ans );
        merge( arr, i, mid, j, ans );
    }
    long long int inversionCount(long long arr[], long long N){
        long ans = 0;
        mergeSort( arr, 0, N-1, ans );
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends

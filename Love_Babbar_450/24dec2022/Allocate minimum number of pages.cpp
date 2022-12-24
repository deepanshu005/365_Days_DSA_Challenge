// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible( int A[], int N, int M, int mid ){
        int studCount = 1;
        int pageSum = 0;
        for( int i=0; i<N; i++ ){
            if( pageSum + A[i] <= mid ){
                pageSum += A[i];
            }
            else {// means we need atleast one more student
                studCount++;
                if( studCount>M || A[i]>mid ){
                    return false;
                }
                pageSum = A[i];// updating pageSum as we shifted to new student
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M){
        if( M>N ){// ydi books zyaada hui number of students se 
            return -1;
        }
        int pTotal = 0;
        for( int i=0; i<N; i++ ){
            pTotal += A[i];
        }
        int ans = -1;
        int i = 0;
        int j = pTotal;
        int mid;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( isPossible(A, N, M, mid) ){// mtlb mid jitne pages ek student ko allocate krna possible h ya nhi
                ans = mid;// ydi possible h to usse jyaadda pages bhi allocate kiye jaa skte h hence putting j before mid
                j = mid-1;
            }
            else{// mid jitne pages allocate krna possible nhi mtlb humme pages increase krne honge hence putting i after mid
                i = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

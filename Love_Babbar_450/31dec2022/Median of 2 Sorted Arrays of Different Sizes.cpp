// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2){
        int a = arr1.size();
        int b = arr2.size();
        int c = a+b;
        int k = 0;
        int i = 0;
        int j = 0;
        double prev = -1;
        double curr = -1;
        while( i<a and j<b and k<=c/2 ){
            if( arr1[i]<arr2[j] ){
                prev = curr;
                curr = arr1[i];
                i++;
            }
            else{
                prev = curr;
                curr = arr2[j];
                j++;
            }
            k++;
        }
        if( k<=c/2 ){
            while( i<a and k<=c/2 ){
                prev = curr;
                curr = arr1[i];
                i++;
                k++;
            }
            while( j<b and k<=c/2 ){
                prev = curr;
                curr = arr2[j];
                j++;
                k++;
            }
        }
        if( c%2 )
            return curr;
        
        return (prev+curr)/2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends

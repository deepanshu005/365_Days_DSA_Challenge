// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k){
        sort( a, a+n );
        int i=0;
        int sum = 0;
        while( a[i]<=0 && i<k  ){// converting all negatives to positives
            a[i] = a[i]*(-1);
            i++;
        }
        sort( a, a+n );
        //now just switching the element at index 0 
        // because if all elements are +ve and k is odd then at the end atleast one element will be negative and
        //since the element at index 0 is smallest hence we can bear its loss for maximum sum
        while( i<k ){
            a[0] = a[0]*(-1);
            i++;
        }
        i = 0;
        while( i<n ){
            sum += a[i];
            i++;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends

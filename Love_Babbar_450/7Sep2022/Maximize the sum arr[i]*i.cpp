//CPP DSA Love babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n){
        sort( a, a+n );
        long sum = 0;
        long c = pow(10,9) + 7;// ( 1000000007)
        for( int i=0; i<n; i++ ){
            sum += ((long)a[i]*i)%c; 
            // Because
            // ( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
            // ( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
            // ( a – b) % c = ( ( a % c ) – ( b % c ) ) % c
        }
        return sum%c;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends

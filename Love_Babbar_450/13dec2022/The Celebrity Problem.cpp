// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n){
        for( int j=0; j<n; j++ ){
            int i=0;
            for( i=0; i<n; i++ ){
                if( !M[i][j] and i!=j )
                    break;
            }
            //std::cout<<i<<" " << "Deepanshu" <<endl;  
            if( i==n ){
                int k=0;
                for( k=0; k<n; k++ ){
                    if( M[j][k] )
                        break;
                }
                if( k==n  )
                    return j;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends

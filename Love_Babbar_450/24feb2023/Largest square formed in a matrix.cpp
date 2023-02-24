// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(mat[i][j]){
                    int sq1 = mat[i-1][j];
                    int sq2 = mat[i][j-1];
                    int sq3 = mat[i-1][j-1];
                    int minimum = min({sq1,sq2,sq3});
                    if(minimum == 0)continue;
                    else mat[i][j] = minimum + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                ans = max(ans,mat[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

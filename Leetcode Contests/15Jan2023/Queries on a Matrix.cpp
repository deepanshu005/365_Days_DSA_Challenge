// CPP Leetcode Contest
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void solve( vector<vector<int>>&ans, vector<int>query ){
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            for( int i=r1; i<=r2; i++ ){
                for( int j=c1; j<=c2; j++ ){
                    ans[i][j] += 1;
                }
            }
        return;
    }
    vector<vector<int>> solveQueries(int n, vector<vector<int>> queries) {
        vector<vector<int>> ans( n, vector<int>(n,0));
        for( int k=0; k<queries.size(); k++ ){
            solve(ans,queries[k]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends

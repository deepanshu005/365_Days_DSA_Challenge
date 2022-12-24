// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // aggressive bole to hamesha jhgdne k mood m
    bool isPossible( vector<int> stalls, int n, int k, int mid ){
        int cowCount = 1;// considering 1st cow
        int pos = stalls[0];// assigning 1st postion to the first cow
        
        for( int i=0; i<n; i++ ){
            if( stalls[i] - pos >= mid ){// means do posiions k beech enough gap h such that those cows will not fight
                cowCount++;
                if( cowCount==k )
                    return true;
                pos = stalls[i];// cow placed at another position
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort( stalls.begin(), stalls.end() );
        int i = 0;
        int j = stalls[n-1];
        int ans = -1;
        int mid;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( isPossible( stalls, n, k, mid )){// yha right subarray mein jaa rhe coz we wanna maximize the distance
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends

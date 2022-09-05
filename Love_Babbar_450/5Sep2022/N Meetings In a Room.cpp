// Love Babbar CPP DSA 450 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // In comparator fxn, if we want to swap then return false
        static bool cmp( pair<int,int> a, pair<int,int> b ){// Sorting on the basis end timing of meeting
            if( a.second> b.second )
                return false;
            else if( a.second == b.second && a.first> b.first )
                return false;
            return true;
        }
        int maxMeetings(int start[], int end[], int n){
            vector<pair<int,int>> vec;
            int count = 1;
            for( int i=0; i<n; i++ ){
                vec.push_back( make_pair( start[i], end[i] ));
            }
            sort( vec.begin(), vec.end(), cmp );
            // the meeting which will end first will be on top
            int limit = vec[0].second;
            for( int i=1; i<n; i++){
                if( vec[i].first > limit ){
                    limit = vec[i].second;
                    count++;
                }
            }
            return count;
        }
};
// In case of pair, inbuilt sorting algorithm will sort according to the first element of pair
// and if two first elements are same of two any two pairs then they will be sorted according to the second element of both pairs in ascending order

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends

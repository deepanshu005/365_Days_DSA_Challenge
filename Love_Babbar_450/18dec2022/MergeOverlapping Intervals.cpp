// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
// bool comp( vector<int>a, vector<int>b){
//     return a[0]<b[0];
// }
//question mein n vecors honge and each vector is of length of 2
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end() );
    vector<int>temp = intervals[0];
    int n = intervals.size();
    for( int i=0; i<n; i++ ){
        if( intervals[i][0]<=temp[1] ){
            temp[1] = max( temp[1], intervals[i][1] );
        }
        else{
            ans.push_back(temp);
            temp = intervals[i];
        }
    }
    ans.push_back(temp);
    return ans;
}



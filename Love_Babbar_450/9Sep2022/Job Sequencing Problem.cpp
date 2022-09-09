// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool cmp( pair<int,int> a, pair<int,int> b ){
        return ( a.first > b.first );
    }
    public:
    vector<int> JobScheduling(Job arr[], int n){ 
        vector< pair<int,int> > vec;//profit, deadline
        int Max = INT_MIN;
        for( int i=0; i<n; i++ ){
            vec.push_back( make_pair(arr[i].profit, arr[i].dead) );
            if( arr[i].dead > Max )
                Max = arr[i].dead; 
        }
        sort( vec.begin(), vec.end(), cmp );
        int array[Max+1] = {};
        int count = 0;
        int pro = 0;
        for( int i=0; i<n; i++ ){// to traverse in vector
            for( int j = vec[i].second; j>0; j--){
                if( array[j] == 0){
                    array[j] = i;
                    count++;
                    pro += arr[i].profit;
                    break;
                }
            }
        }
        
        return {count,pro};    
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends

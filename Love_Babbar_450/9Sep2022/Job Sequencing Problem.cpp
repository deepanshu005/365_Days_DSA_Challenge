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

//Greedy approach here is we will try doing our jobs as nearest possible to the deadline
class Solution 
{
    static bool cmp( Job a, Job b ){
        return a.profit > b.profit;
    }//Means if profit of b is more then return false to the swap fxn saying that its not true it needs to be swapped
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
        sort( arr, arr+n, cmp );
        int Max = arr[0].dead;
        for( int i=0; i<n; i++ ){
            if( arr[i].dead>Max )
                Max = arr[i].dead;
        }
        int seq[Max+1];
        for( int i=0; i<=Max; i++ )
            seq[i] = -1;
        
        int count = 0;
        int profit = 0;
        for( int i=0; i<n; i++ ){
            for( int j=arr[i].dead; j>0; j-- ){
                if( seq[j] == -1 ){
                    seq[j] = i;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {count, profit};
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

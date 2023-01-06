// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    
    vector<int> prevSmallerElement( int arr[], int n) {
        stack<int> st;
        vector<int>vec(n);
        st.push(-1);
        int i=0;
        while(i<n){
            int curr = arr[i];
            while( st.top() != -1 and arr[st.top()]>=curr ){
                st.pop();
            }
            vec[i] = st.top();
            st.push(i);// we are storing the indexes of elements in stack
            i++;
        }
        return vec;
    } 
    
    vector<int> nextSmallerElement( int arr[], int n) {
        stack<int> st;
        vector<int>vec(n);
        st.push(-1);
        while(n--){
            int curr = arr[n];
            while( st.top() != -1 and arr[st.top()]>=curr ){
                st.pop();
            }
            vec[n] = st.top();
            st.push(n);// we are storing the indexes of elements in stack
        }
        return vec;
    } 
    // N = 7
    // arr[] = {6,2,5,4,5,1,6}
    // next = {1,5,3,5,5,-1,-1}
    // prev = {-1,-1,1,1,3,-1,5}
    // bre = {1,5,1,3,2,7,1}
    // newArea = {6,10,5,12,10,7,6}

    //Function to find largest rectangular area possible in a given histogram.
    int getMaxArea( int arr[], int n){// Simply copy pasted the code from histogram problem
        int area = 0;
        
        vector<int> next(n);
        next = nextSmallerElement(arr, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(arr, n);
        
        for( int i=0; i<n; i++ ){
            int len = arr[i];
            if( next[i]==-1 ){// mtlb jis building se koi kam nahi wo ahr jagah expand kr skti h 
                next[i] = n;// hrnce giving it as n i.e., total number of buildings
            }
            int bre = next[i]-prev[i]-1;
            int newArea = len*bre;// newArea calculates the max possible area for each index then comparing which one is maximum
            area = max(newArea, area);
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxi = getMaxArea( M[0], m );
        
        for( int i=1; i<n; i++ ){// Updating in the matrix itself
            for( int j=0; j<m; j++ ){
                if( !M[i][j] )// if zero is there leave that element as it is coz it wll break the height of that building
                    M[i][j] = 0;
                
                else// else add the previous height of that building
                    M[i][j]+=M[i-1][j];
                
            }
            maxi = max(maxi, getMaxArea( M[i], m) );
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends

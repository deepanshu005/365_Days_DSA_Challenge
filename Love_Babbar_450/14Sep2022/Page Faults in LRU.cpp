// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//Least recently used means jo kaafi time phle use hua tha
class Solution{
public:
    int pageFaults(int N, int C, int page[]){
        //making vector such that left most element is least recently used element
        //and right most element is most recently used
        int fault=0;
        vector<int> vec;
        
        for(int i=0;i<N;i++){//traversing the page array
            int j = 0;
            for(  j=0; j<vec.size(); j++ ){//to traverse on vector
                if( page[i] == vec[j] )
                    break;
            }
            if( j==vec.size() ){// not found and j has reached to the last 
                if( j==C )// Means capacity is full and we need to replace the LRU element
                    vec.erase( vec.begin() );
                vec.push_back( page[i] );
                fault++;
            }  
            else{//found
                vec.erase( vec.begin() + j );
                vec.push_back( page[i]);
            }
        }
        return fault;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

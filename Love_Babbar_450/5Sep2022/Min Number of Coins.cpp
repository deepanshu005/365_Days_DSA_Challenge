// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> vec;
        while( N>0 ){
            if( N>=2000 ){
                N -= 2000;
                vec.push_back(2000);
            }
            else if( N>=500 ){
                N -= 500;
                vec.push_back(500);
            }
            else if( N>=200 ){
                N -= 200;
                vec.push_back(200);
            }
            else if( N>=100 ){
                N -= 100;
                vec.push_back(100);
            }
            else if( N>=50 ){
                N -= 50;
                vec.push_back(50);
            }
            else if( N>=20 ){
                N -= 20;
                vec.push_back(20);
            }
            else if( N>=10 ){
                N -= 10;
                vec.push_back(10);
            }
            else if( N>=5 ){
                N -= 5;
                vec.push_back(5);
            }
            else if( N>=2 ){
                N -= 2;
                vec.push_back(2);
            }
            else if( N>=1 ){
                N -= 1;
                vec.push_back(1);
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends

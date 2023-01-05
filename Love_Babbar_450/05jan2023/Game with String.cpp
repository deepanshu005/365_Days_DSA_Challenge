// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define PIC pair<int, char>

class Compare {
public:
    bool operator()(PIC below, PIC above){
        if (below.first < above.first) {
            return true;
        }
        return false;
    }
};
 

class Solution{
public:
// min sum of squares chahiye to jiski jyaada freq usko phle remove karo
    int minValue(string str, int k){
        unordered_map<char,int> mp;
        for( int i=0; str[i]!='\0'; i++ ){// Storing freq of each element
            mp[str[i]]++;
        }
        priority_queue<PIC, vector<PIC>, Compare>pq;
        for( auto x : mp ){// pushing pairs to pq
            pq.push( {x.second, x.first} );
        }
        while( k-- ){// removing k elments 
            PIC pr = pq.top();
            pq.pop();
            pr.first--;// decreasing freq of removed element
            pq.push(pr);
        }
        int ans = 0;
        while( !pq.empty() ){
            PIC pr = pq.top();
            pq.pop();
            ans += (pr.first)*(pr.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// CPP DSA Love Babbar 450
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// refer this https://youtu.be/-xyju56LLMI
struct myComp {
     bool operator()( pair<int, int> a, pair<int, int> b){
        if( a.first==b.first )// first mein freq stored thi humaare paas
            return a.second > b.second;// ydi freq same hai to hum chahte h jiski corres value choti ho wo uski priority jyaada ho
        return a.first < b.first;// true tb return krwaamna hota h jb we want to swap
        // yha ydi b.first bda hua to we want to swap coz we want ki jiski freq jyaada ho uski priority jyaada hogi
    }
};

int main() {
	int t;
	cin>>t;
	while( t-- ){
	    int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    for( int i=0; i<n; i++ ){
	        cin>>arr[i];
	    }
	    unordered_map<int, int> m;
	    for( int i=0; i<n; i++ ){
	        m[arr[i]]++;
	    }
	    priority_queue<pair<int,int>, vector<pair<int,int>> ,myComp > pq;
	    for( auto it : m ){
	        pq.push( {it.second, it.first} );
	    }
	    while( !pq.empty() ){
	        pair<int,int> pr = pq.top();
	        while( pr.first-- ){
	            cout<<pr.second<<" ";
	        }
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}

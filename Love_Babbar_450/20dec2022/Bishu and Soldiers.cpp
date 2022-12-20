// CPP DSA Love Babbar 450
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int N, Q;
	cin>>N;
	vector<int> vec(N,0);
	for( int i=0; i<N; i++ ){
		int x;
		cin>>x;
		vec[i] = x;
	}
	//sort( vec.begin(), vec.end() );
	cin>>Q;
	int M;
	while(Q--){
		int sum = 0;
		int count = 0;
		cin>>M;
		for( int i=0; i<N; i++ ){
			if( vec[i]<=M ){
				sum+=vec[i];
				count++;
			}
		}
		cout<<count<<" "<<sum<<endl;
	}
	return 0;
}

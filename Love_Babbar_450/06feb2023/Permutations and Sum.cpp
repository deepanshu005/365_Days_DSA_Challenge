// CPP DSA Love Babbar 450
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	vector<int> permutaion(int N) {
// Code here
string s = to_string(N);

sort(s.begin(), s.end());
int cnt = 0;
int tot = 0;
do{
tot += stoi(s);
cnt++;
}while(next_permutation(s.begin(), s.end()));
vector<int>res;
res.push_back(cnt);
res.push_back(tot);
return res;

}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.permutaion(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends

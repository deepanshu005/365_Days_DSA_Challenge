// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
string FirstNonRepeating(string A) {
    int map[26] = {0};
    queue<int> q;
    
    for(int i=0; i<A.length(); i++) {
        int key = A[i] - 'a';
        map[key]++;
        
        if(map[key] == 1)
            q.push(A[i]);
        
        while(!q.empty() && map[q.front() - 'a'] != 1)
            q.pop();
            
        if(q.empty())
            A[i] = '#';
        else A[i] = q.front();
    }
    
    return A;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends

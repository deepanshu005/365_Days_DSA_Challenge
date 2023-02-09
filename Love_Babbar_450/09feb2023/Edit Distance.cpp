// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mini(int x,int y,int z){
       int k=min(x,y);
       k=min(k,z);
       return k;
   }
   int editDistance(string s, string p) {
       int n=s.size();
       int m=p.size();
       int t[n+1][m+1];
       for(int i=0;i<=n;i++){
           for(int j=0;j<m+1;j++){
               if(i==0){
                   t[i][j]=j;
               }
               else if(j==0){
                   t[i][j]=i;
               }
               else if(s[i-1]==p[j-1]){
                   t[i][j]=t[i-1][j-1];
               }
               else{
                   t[i][j]=1 + mini(t[i][j-1],t[i-1][j],t[i-1][j-1]);
               }
           }
       }
       return t[n][m];
   }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

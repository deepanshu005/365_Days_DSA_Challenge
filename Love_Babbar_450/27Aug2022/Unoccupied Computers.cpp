// GFG Love Babbar DSA 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int k, string str) {
        map<char,bool> visited;
        int n = str.size();
        int count = 0;
        for( int i=0; i<n; i++ ){
        if( visited.find(str[i]) != visited.end() ){//phle aa chuka h 
            if( visited[str[i]] )// phle aa chuka h and computer mil gya tha, ab jaa rha h
                k++;
            else
                continue;// phle aaya tha but computer nhi mila ab jaa rha h
        }
        else if( visited.find(str[i]) == visited.end() && k>0 ){
            // first time aa rha h and computer available h
            visited[str[i]] = true;
            k--;
        }
        else{//phli baar aa rha h and computer available nhi h
            count++;
            visited[str[i]] = false;//false means dint get computer
        }
    }
    return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

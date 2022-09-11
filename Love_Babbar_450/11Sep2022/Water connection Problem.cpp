// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void dfs(int u, int start, vector<vector<pair<int,int>>> &adj, vector<vector<int>> &ans, int d){
            if(adj[u].size() == 0){
                ans.push_back({start,u,d});
                return;
            }
            for(auto x: adj[u])
                dfs( x.first,start,adj,ans,min(d,x.second));
    
            return;
            
        }
    public:
        vector<vector<int>> solve(int n,int pp,vector<int> a,vector<int> b,vector<int> d){
            // n means number of houses i.e., number f nodes in a graph
            // pp means number of pipes i.e., number of edges
            set<int> s;
            vector<vector<pair<int,int>>> adj(n+1);//adj is adjacency list and it is vector of vectors of pairs
            for(int i=0; i<pp; i++){
                adj[a[i]].push_back({b[i],d[i]});
                s.insert(a[i]);
            }
            for(int i=0; i<pp; i++){
                s.erase(b[i]);
            }
            vector<vector<int>> ans;
            for(auto it:s){
                dfs(it,it,adj,ans,INT_MAX);
            }
            return ans;
        }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends

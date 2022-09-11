//CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        int vis[V] = {};
        vis[0] = 1;//Means we have visited that node
        queue<int> q;
        q.push(0);
        while( !q.empty() ){// loop will be runing until queue got empty
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for( auto i : adj[node] ){//to traverse the vector corresponding to the node
                if( vis[i] == 0 ){//Means we have'nt visited it yet
                    q.push(i);//pushing the node which we had'nt visited yet
                    vis[i] = 1;// marking the node visited
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

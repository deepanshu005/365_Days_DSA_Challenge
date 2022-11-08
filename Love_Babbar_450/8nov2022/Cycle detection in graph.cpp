// CPP DSA Love Babbar 450
bool helper( int node, int parent, vector<int>adj[], vector<int>&vis ){
        vis[node] = 1;
        for( int i=0; i<adj[node].size(); i++ ){
            if( vis[adj[node][i]]==0 ){
                if( helper( adj[node][i], node, adj, vis ))    return true;
            }
            else if( adj[node][i] != parent ){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for( int i=0; i<V; i++ ){
            if( vis[i]==0 ){
                if(helper( i,-1,adj, vis))  return true;
            }
        }
        return false;
    }
};

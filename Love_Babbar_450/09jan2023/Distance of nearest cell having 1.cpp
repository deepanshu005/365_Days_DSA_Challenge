// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    //Simpli the sibling problem of rotten oranges
    // we took two matrices one for visited cells adn other for storing distances of nearest 0's of each cell
    
	vector<vector<int>> nearest(vector<vector<int>>grid){
	    int row = grid.size();
	    int col = grid[0].size();
	    vector<vector<int>> dis(row, vector<int>(col,0));
	    vector<vector<int>> vis(row, vector<int>(col,0));
	    // { {i,j}, distance }
	    queue<pair<pair<int,int>,int>> q;
	    for( int i=0; i<row; i++ ){
	        for( int j=0; j<col; j++ ){
	            if( grid[i][j] ){
	                dis[i][j] = 0;
	                q.push( {{i,j},0} );
	            }
	            vis[i][j] = grid[i][j];
	        }
	    }
	    int d = 0;//   l  r  t  b
	    int dRow[] = { 0, 0,-1, 1};
	    int dCol[] = {-1, 1, 0, 0 };
	    
	    while( !q.empty() ){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int dst = q.front().second;
	        q.pop();
	        for( int i=0; i<4; i++ ){
	            int nRow = r + dRow[i];
	            int nCol = c + dCol[i];
	            if( nRow>=0 and nRow<row and nCol>=0 and nCol<col and vis[nRow][nCol]==0 ){
	                vis[nRow][nCol] = 1;
	                dis[nRow][nCol] = dst+1;
	                q.push( {{nRow,nCol},dst+1} );
	            }
	        }
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
